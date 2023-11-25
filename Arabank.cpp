#include <iostream>
#include <locale>
#include <fstream>
#include <string.h>

using namespace std;

// constantes
const int QTD_MAX = 50;

//////////////////////////////////
///// Structs ///                   
///////////////////////////

struct Conta {
    char num_conta [10];
    char num_agencia [10];
    char nome [50];
    char CPF [12];
    float saldo;
};

///////////////////////////////
/// Protótipos ///       
/////////////////////////

void menu (int &opcao);
int Buscador (Conta contas [], int qtd, int escolha, char busca []);
void cadastrar_conta (Conta contas [], int &qtd);
int salvaDados (Conta contas [],int qtd);
void LeDados (Conta contas [], int &qtd);
void alterar_conta ( Conta contas[],int qtd );
void excluir_conta (Conta contas [],int &qtd);
void mostra_contas (Conta contas [],int qtd);
void mostraTodas (Conta contas [],int qtd);
void consultaSaldo (Conta contas [], int qtd);

////////////////////////////////////////////////////////

int main (){
    // mostrar caracteres especiais no terminal
    setlocale(LC_ALL, "portuguese");
    
    // vetor struct
    Conta contas [QTD_MAX];
    Conta c;

    int qtd = 0;
    int op;
    // carrega dados anteriores 
    LeDados (contas,qtd);

    do {
        system ("cls");
        menu (op);
        
        switch (op) {
            case 1: 
                // cadastrar conta corrente 
                cadastrar_conta (contas,qtd);
                break;
            case 2:
                // alterar dados da conta corrente
                alterar_conta (contas,qtd);
                break;
            case 3:
                // excluir conta 
                excluir_conta (contas,qtd);
                break;
            case 4:
                // consultar saldo
                consultaSaldo (contas,qtd);
                break;
            case 5:
                //Deposito
                break;
            case 6:
                //Realizar saque
                break;
            case 7:
                //Transferir Valores
                break;
            case 8:
                // mostra todas as contas
                mostraTodas (contas,qtd);
                break;
            case 9:
                //Extrato 
                break;
            case 10:
                cout << "\n";
                cout << "Sistema finalizado com sucesso " << endl << endl;
                
                cout << "\t*------------------------------------------*" << endl;
                cout << "\t ---- AGRADECEMOS A PREFERÊNCIA ! ^-^ ----" << endl;
                cout << "\t*------------------------------------------*" << endl << endl;
                
                salvaDados (contas,qtd);
                break;    
            default:
                cout << "\n";
                cout << "--* Opcao Invalida *-- " << endl;
                cout << "Escolha uma opcao entre 1 e 10 " << endl;
                system ("pause");
                break;
        }
    

    } while (op != 10); 
    

    return 0;
}

///////////////////////////////////////////////////////////////////////////////

void menu (int &opcao){
   system ("color 2");
    
    cout << "\t ******************************* " << endl;
    cout << "\t * ARABANCO - SEMPRE COM VOCÊ !! * " << endl;
    cout << "\t ******************************* " << endl << endl;

    cout << "------------------ MENU -----------------------\n" << endl; 
    cout << "| 1.)\t Cadastrar conta corrente. " << endl;
    cout << "| 2.)\t Alterar dados de uma conta corrente" << endl;
    cout << "| 3.)\t Excluir uma conta corrente" << endl;
    cout << "| 4.)\t Consultar saldo" << endl;
    cout << "| 5.)\t Fazer depósito" << endl;
    cout << "| 6.)\t Realizar saque" << endl;
    cout << "| 7.)\t Transeferir valores" << endl;
    cout << "| 8.)\t Mostrar todas as contas e saldos" << endl;
    cout << "| 9.)\t Emitir extrato de conta " << endl;
    cout << "| 10.)\t Desenvolvedor" << endl;
    cout << "| 11.)\t Sair" << endl;
    cout << "----------------------------------------------- \n"<< endl << endl;
    cout << "------> Escolha uma opção: " ;
    cin >> opcao;

}
// --------------------
// Usada constantemente
// ---------------------
//  Valores para 'escolha': 
//	1 = Buscar Número da Conta
//	2 = Buscar Número da Agência
//	3 = Buscar Nome 
//	4 = Buscar CPF do Titular
//

int Buscador (Conta contas [], int qtd, int escolha, char busca []){
    for (int i = 0; i < qtd; i++){
            switch (escolha){
            case 1:
                if (strcmp(busca,contas[i].num_conta) == 0){
                return i;
                }
                break;
            case 2:
                if (strcmp (busca,contas[i].num_agencia) == 0 ){
                    return i;
                }
                break;
            case 3:
                if ( strcmp (busca,contas[i].nome) == 0 ){
                    return i;
                }
                break;
            case 4:
                if (strcmp (busca,contas[i].CPF) == 0 ){
                    return i;
                }
                break;     
        }
    }
    return -1;

}

void cadastrar_conta (Conta contas [], int &qtd){
    system ("cls");
    system ("color 3");

    Conta c;

    cout << "\t ***************************************** " << endl;
    cout << "\t ******** CRIAR CONTA CORRENTE ********** " << endl;
    cout << "\t ***************************************** " << endl << endl;

    if (qtd >= QTD_MAX){
        system ("color 4");
        cout << "\t *---- ERRO ! ----*"<< endl;
        cout << "Agenda cheia" << endl;

        system("pause");
        return;
    }

    cout << "- Insira o numero da conta: ";
    cin >> c.num_conta;
    cout << "\n";
    cout << "- Insira o número da agência: ";
    cin >> c.num_agencia;
    cout << "\n";
    cout << "- Insira o nome do titular: ";
    cin >> c.nome;
    cout << "\n";
    cout << "- insira o CPF do titular: ";
    cin >> c.CPF;
    cout << "\n";
    cout << "- Qual é o saldo inicial ? ";
    cin >> c.saldo;
    cout << "\n";

    if (c.saldo < 0 ){
        cout << system ("color 4");
        cout << "\t Saldo insuficiente !! " << endl;
        cout << "OBS: O seu saldo não pode ser negativo para a criação da conta " << endl;
        system ("pause");
        return;
    }

    contas [qtd++] = c;

    cout << "\t**************************************************" << endl;
    cout << "\t| --- A SUA CONTA FOI CRIADA COM SUCESSO !!! --- | " << endl;
    cout << "\t**************************************************" << endl << endl;

    system ("pause");
}

///// Gera o arquivo que armazena as informações do struct  
int salvaDados (Conta contas [],int qtd){

    ofstream fout;

    fout.open ("contas_corrente.bin", ios :: binary);
    if (!fout){
        cout << system ("color 4");
        cout << "Erro de criação !";
        return 0;
    }

    fout.write ((char * ) &qtd, sizeof (qtd));
    fout.write ((char *) contas, sizeof (Conta) * QTD_MAX );

    fout.close();

}

// Lê o arquivo anteriormente gerado
void LeDados (Conta contas [], int &qtd){

    ifstream fin;
    fin.open ("contas_corrente.bin", ios :: binary);
    if (!fin){
        cout << system ("color 4");
        cout << "Erro de leitura !";
        return;
    }

    fin.read ((char * ) &qtd, sizeof (qtd));
    fin.read ((char *) contas, sizeof (Conta) * QTD_MAX );

    fin.close ();

}

void alterar_conta ( Conta contas[],int qtd){
    system ("cls");
    system ("color 6");
    cout << "\t *---------------------------------------------*" << endl;
    cout << "\t ---------- Alterar Dados da Conta ---------- " << endl;
    cout << "\t *---------------------------------------------*" << endl << endl;
    char conta [50];
    char agencia [50];
    
    cout << "Insira um Número de Conta Corrente: ";
    cin >> conta;
    cout << "Insira a Agência da Conta Corrente:";
    cin >> agencia;
   
    int BuscaConta = Buscador (contas,qtd,1,conta);
    int BuscaAgencia = Buscador (contas,qtd,2,agencia);

    
    if (BuscaConta == -1 && BuscaAgencia == -1 ){
        cout << "\n";
        cout << system ("color 4");
        cout << "Atenção !" << endl;
        cout << "Conta ou Agência inválida " << endl;
        system ("pause");

    }
    else {
        cout << "\n";
        system ("color 2");
        cout << " -- Digite os dados da nova conta -- " << endl << endl;
        cout << "Nome do titular: ";
        cin >> contas[BuscaConta].nome;
        cout << "\n";
        cout << "CPF do titular: ";
        cin >> contas[BuscaAgencia].CPF;
        cout << "\n";
        cout << "Conta alterada !!!" << endl << endl;
        system ("pause");
    }
    
}

void excluir_conta (Conta contas [],int &qtd){
    system ("cls");
    system ("color 2");
    
    cout << "\t *----------------------------------------*" << endl;
    cout << "\t | --------- EXCLUIR CONTA  -------------| " << endl;
    cout << "\t *---------------------------------------* " << endl << endl;
    
    char conta [50];
    char agencia [50];
    
    cout << "Insira um Número de Conta Corrente: ";
    cin >> conta;
    cout << "\n";
    cout << "Insira a Agência da Conta Corrente: ";
    cin >> agencia;

    int BuscaConta = Buscador (contas,qtd,1,conta);
    int BuscaAgencia = Buscador (contas,qtd,2,agencia);

    if (BuscaConta == -1 && BuscaAgencia == -1 ){
        system ("color 4");
        cout << "Atenção !" << endl;
        cout << "Conta ou Agência inválida ";
        system ("pause");
    }
    else {
        for (int i = BuscaConta; i < qtd - 1;i++){
            contas [i] = contas [i+1];
        }
        qtd--;
        system ("color b");
        cout << "---> Conta Excluida !!" << endl;
        system ("pause");

    }
   
}

void mostraTodas (Conta contas [],int qtd){ 
    system ("cls");
    system ("color 5");
    cout << "\n";
    cout << "*************************************************************** " << endl;
    cout << "---------------- TODAS AS CONTAS E SALDOS --------------------* " << endl;
    cout << "***************************************************************" << endl << endl;

    for (int i = 0; i < qtd; i++){
        cout << "\t CONTA: " << contas[i].num_conta << "\t" << 
        "AGÊNCIA:" << contas[i].num_agencia << "\t"
         << "NOME: " << contas[i].nome << "\t" 
             << "CPF: " << contas[i].CPF << "\t" 
                 << "SALDO: " << contas[i].saldo << "\t" <<"\n" << "\n";   

    }

    system ("pause");

}


void consultaSaldo (Conta contas [], int qtd){
    system ("cls");
    system ("color e");

    cout << "\n";
    cout << "\t*************************************************************** " << endl;
    cout << "\t* -----------------  CONSULTAR SALDO  ----------------------- * " << endl;
    cout << "\t***************************************************************" << endl << endl;

    char conta [50];
    char agencia [50];
     
    cout << "--> Digite o número da conta corrente: ";
    cin >> conta;
    cout << "--> Digite o número da agência:  ";
    cin >> agencia;
    
    int BuscaConta = Buscador (contas,qtd,1,conta);
    int BuscaAgencia = Buscador (contas,qtd,2,agencia);


    if (BuscaConta == -1 && BuscaAgencia == -1 ){
        system ("color 4");
        cout << "\n";
        cout << "Atenção !" << endl;
        cout << "Conta ou Agência inválida " << endl;
        system ("pause");

    }
    else {
        for ( int i = 0; i < qtd ; i++){
            system ("cls");
            system ("color d");
            cout << "\n";
            cout << "-------------------------------------------" << endl;
            cout << "| ------------ SALDO --------------------- |" << endl;
            cout << "-------------------------------------------" << endl << endl;

            cout << "--> Usuário: " << contas[BuscaAgencia].nome << endl;
            cout << "--> Saldo atual: " << contas[BuscaConta].saldo << "R$ " << endl; 
            
            system ("pause");
        }

    }

    system ("pause");
}
