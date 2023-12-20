
#include <iostream>
#include <locale>
#include <fstream>
#include <string.h>
#include <ctime>

using namespace std;

// constantes
const int QTD_MAX = 50;

//////////////////////////////////
///// Structs ///                   
///////////////////////////

struct Transacao {
    char tipo[35];
    float valor;
    char data[20];
    char hora[20];
    float saldo_momento;
};

struct Conta {
    char num_conta [10];
    char num_agencia [10];
    char nome [50];
    char CPF [12];
    float saldo;
    Transacao extrato[50];
    int qtd_transacoes = 0;
};

///////////////////////////////
/// Protótipos ///       
/////////////////////////

/**
 * Função que exibe o menu principal do sistema.
 * 
 * @param opcao Referência para a variável que armazena a opção escolhida pelo usuário.
 */
void menu (int &opcao);

/**
 * Função que busca uma conta corrente no vetor de contas.
 * 
 * @param contas Vetor de contas correntes.
 * @param qtd Quantidade de contas correntes no vetor.
 * @param escolha Opção de busca (1 = Número da Conta, 2 = Número da Agência, 3 = Nome, 4 = CPF).
 * @param busca Valor a ser buscado.
 * @return Índice da conta encontrada ou -1 se não encontrada.
 */
int Buscador (Conta contas [], int qtd, int escolha, char busca []);

/**
 * Função que cadastra uma nova conta corrente.
 * 
 * @param contas Vetor de contas correntes.
 * @param qtd Referência para a quantidade de contas correntes no vetor.
 */
void cadastrar_conta (Conta contas [], int &qtd);

/**
 * Função que salva os dados das contas correntes em um arquivo binário.
 * 
 * @param contas Vetor de contas correntes.
 * @param qtd Quantidade de contas correntes no vetor.
 * @return 0 em caso de erro na criação do arquivo, 1 caso contrário.
 */
int salvaDados (Conta contas [],int qtd);

/**
 * Função que lê os dados das contas correntes de um arquivo binário.
 * 
 * @param contas Vetor de contas correntes.
 * @param qtd Referência para a quantidade de contas correntes no vetor.
 */
void LeDados (Conta contas [], int &qtd);

/**
 * Função que altera os dados de uma conta corrente.
 * 
 * @param contas Vetor de contas correntes.
 * @param qtd Quantidade de contas correntes no vetor.
 */
void alterar_conta ( Conta contas[],int qtd );

/**
 * Função que exclui uma conta corrente.
 * 
 * @param contas Vetor de contas correntes.
 * @param qtd Referência para a quantidade de contas correntes no vetor.
 */
void excluir_conta (Conta contas [],int &qtd);

/**
 * Função que exibe todas as contas correntes e seus saldos.
 * 
 * @param contas Vetor de contas correntes.
 * @param qtd Quantidade de contas correntes no vetor.
 */
void mostraTodas (Conta contas [],int qtd);

/**
 * Função que consulta o saldo de uma conta corrente.
 * 
 * @param contas Vetor de contas correntes.
 * @param qtd Quantidade de contas correntes no vetor.
 */
void consultaSaldo (Conta contas [], int qtd);

/**
 * Função que realiza um depósito em uma conta corrente.
 * 
 * @param contas Vetor de contas correntes.
 * @param qtd Quantidade de contas correntes no vetor.
 */
void realizar_deposito(Conta contas[], int qtd);

/**
 * Função que realiza um saque em uma conta corrente.
 * 
 * @param contas Vetor de contas correntes.
 * @param qtd Quantidade de contas correntes no vetor.
 */
void realizar_saque(Conta contas[], int qtd);

/**
 * Função que transfere valores entre duas contas correntes.
 * 
 * @param contas Vetor de contas correntes.
 * @param qtd Quantidade de contas correntes no vetor.
 */
void transferir_valores(Conta contas[], int qtd);

/**
 * Função que registra uma transação em uma conta corrente.
 * 
 * @param conta Referência para a conta corrente.
 * @param tipo Tipo da transação.
 * @param valor Valor da transação.
 */
void registrar_transacao(Conta& conta, const char* tipo, float valor);

/**
 * Função que emite o extrato de uma conta corrente.
 * 
 * @param contas Vetor de contas correntes.
 * @param qtd Quantidade de contas correntes no vetor.
 */
void emitir_extrato(Conta contas[], int qtd);

/**
 * Função que verifica se um CPF é válido.
 * 
 * @param cpf CPF a ser verificado.
 * @return true se o CPF é válido, false caso contrário.
 */
bool cpfValido(char cpf[11]);

/**
 * Função que verifica se um nome é válido.
 * 
 * @param nome Nome a ser verificado.
 * @return true se o nome é válido, false caso contrário.
 */
bool validaNome(char nome[]);

/**
 * Função que verifica se um número é válido.
 * 
 * @param numero Número a ser verificado.
 * @return true se o número é válido, false caso contrário.
 */
bool validaNumero(char numero[]);

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
                realizar_deposito(contas, qtd);
                break;
            case 6:
                //Realizar saque
                realizar_saque(contas, qtd);
                break;
            case 7:
                //Transferir Valores
                transferir_valores(contas, qtd);
                break;
            case 8:
                // mostra todas as contas
                mostraTodas (contas,qtd);
                break;
            case 9:
                //Extrato 
                emitir_extrato(contas, qtd);
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
    cout << "| 10.)\t Sair" << endl;
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
    if (!validaNumero(c.num_conta)) {
        cout << "\n";
        cout << system ("color 4");
        cout << "Número inválido!" << endl;
        system ("pause");
        return;
    }
    cout << "\n";
    cout << "- Insira o número da agência: ";
    cin >> c.num_agencia;
    if (!validaNumero(c.num_agencia)) {
        cout << "\n";
        cout << system ("color 4");
        cout << "Número inválido!" << endl;
        system ("pause");
        return;
    }
    cout << "\n";
    cout << "- Insira o nome do titular: ";
    cin >> c.nome;
    if (!validaNome(c.nome)) {
        cout << "\n";
        cout << system ("color 4");
        cout << "Nome inválido!" << endl;
        system ("pause");
        return;
    }
    cout << "\n";
    cout << "- insira o CPF do titular: ";
    cin >> c.CPF;
    if (!cpfValido(c.CPF)) {
        cout << "\n";
        cout << system ("color 4");
        cout << "CPF inválido!" << endl;
        system ("pause");
        return;
    }
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
    if (!validaNumero(conta)) {
        cout << "\n";
        cout << system ("color 4");
        cout << "Número inválido!" << endl;
        system ("pause");
        return;
    }
    cout << "Insira a Agência da Conta Corrente:";
    cin >> agencia;
    if (!validaNumero(agencia)) {
        cout << "\n";
        cout << system ("color 4");
        cout << "Número inválido!" << endl;
        system ("pause");
        return;
    }
   
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
    if (!validaNumero(conta)) {
        cout << "\n";
        cout << system ("color 4");
        cout << "Número inválido!" << endl;
        system ("pause");
        return;
    }
    cout << "\n";
    cout << "Insira a Agência da Conta Corrente: ";
    cin >> agencia;
    if (!validaNumero(agencia)) {
        cout << "\n";
        cout << system ("color 4");
        cout << "Número inválido!" << endl;
        system ("pause");
        return;
    }

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
    if (!validaNumero(conta)) {
        cout << "\n";
        cout << system ("color 4");
        cout << "Número inválido!" << endl;
        system ("pause");
        return;
    }
    cout << "--> Digite o número da agência:  ";
    cin >> agencia;
    if (!validaNumero(agencia)) {
        cout << "\n";
        cout << system ("color 4");
        cout << "Número inválido!" << endl;
        system ("pause");
        return;
    }  
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

void realizar_deposito(Conta contas[], int qtd) {
    system("cls");
    system("color e");

    cout << "-------------------------------------------" << endl;
    cout << "| ------------ DEPÓSITO ------------------ |" << endl;
    cout << "-------------------------------------------" << endl << endl;

    char conta[50];
    char agencia[50];
    float valor;

    cout << "--> Digite o número da conta corrente: ";
    cin >> conta;
    if (!validaNumero(conta)) {
        cout << "\n";
        cout << system ("color 4");
        cout << "Número inválido!" << endl;
        system ("pause");
        return;
    }
    cout << "--> Digite o número da agência: ";
    cin >> agencia;
    if (!validaNumero(agencia)) {
        cout << "\n";
        cout << system ("color 4");
        cout << "Número inválido!" << endl;
        system ("pause");
        return;
    }

    int indiceConta = Buscador(contas, qtd, 1, conta);
    int indiceAgencia = Buscador(contas, qtd, 2, agencia);

    if (indiceConta == -1 || indiceAgencia == -1) {
        system("color 4");
        cout << "\n";
        cout << "Conta ou agência não encontradas." << endl;
        cout << "Por favor, verifique os dados informados." << endl;
        system("pause");
    } else {
    	
        cout << "\n";
        cout << "------------------------ DADOS DA CONTA ------------------------" << endl;
        cout << "Número da Conta: " << contas[indiceConta].num_conta << endl;
        cout << "Número da Agência: " << contas[indiceAgencia].num_agencia << endl;
        cout << "Nome do titular: " << contas[indiceConta].nome << endl;
        cout << "CPF do titular: " << contas[indiceAgencia].CPF << endl;
        cout << "Saldo atual: R$ " << contas[indiceConta].saldo << endl << endl;

        cout << "--> Informe o valor a ser depositado: R$ ";
        cin >> valor;

        if (valor <= 0) {
            system("color 4");
            cout << "\n";
            cout << "Valor inválido! O valor deve ser positivo." << endl;
            system("pause");
        } else {
            contas[indiceConta].saldo += valor;

            system("color 2");
            cout << "\n";
            cout << "--> Depósito de R$ " << valor << " realizado com sucesso!" << endl;
            cout << "--> Novo saldo: R$ " << contas[indiceConta].saldo << endl;
            registrar_transacao(contas[indiceConta], "Depósito", valor);
            
            system("pause");
        }
    }
}

void realizar_saque(Conta contas[], int qtd) {
    system("cls");
    system("color e");

    cout << "-------------------------------------------" << endl;
    cout << "| ------------ REALIZAR SAQUE ------------ |" << endl;
    cout << "-------------------------------------------" << endl << endl;

    char conta[50];
    char agencia[50];
    float valor;

    cout << "--> Digite o número da conta corrente: ";
    cin >> conta;
    if (!validaNumero(conta)) {
        cout << "\n";
        cout << system ("color 4");
        cout << "Número inválido!" << endl;
        system ("pause");
        return;
    }
    cout << "--> Digite o número da agência: ";
    cin >> agencia;
    if (!validaNumero(agencia)) {
        cout << "\n";
        cout << system ("color 4");
        cout << "Número inválido!" << endl;
        system ("pause");
        return;
    }

    int indiceConta = Buscador(contas, qtd, 1, conta);
    int indiceAgencia = Buscador(contas, qtd, 2, agencia);

    if (indiceConta == -1 || indiceAgencia == -1) {
        system("color 4");
        cout << "\n";
        cout << "Conta ou agência não encontradas." << endl;
        cout << "Por favor, verifique os dados informados." << endl;
        system("pause");
    } else {
    	
        cout << "\n";
        cout << "------------------------ DADOS DA CONTA ------------------------" << endl;
        cout << "Número da Conta: " << contas[indiceConta].num_conta << endl;
        cout << "Número da Agência: " << contas[indiceAgencia].num_agencia << endl;
        cout << "Nome do titular: " << contas[indiceConta].nome << endl;
        cout << "CPF do titular: " << contas[indiceAgencia].CPF << endl;
        cout << "Saldo atual: R$ " << contas[indiceConta].saldo << endl << endl;

        cout << "--> Informe o valor a ser sacado: R$ ";
        cin >> valor;

        if (valor <= 0) {
            system("color 4");
            cout << "\n";
            cout << "Valor inválido! O valor deve ser positivo." << endl;
            system("pause");
        } else if (valor > contas[indiceConta].saldo) {
            system("color 4");
            cout << "\n";
            cout << "Saldo insuficiente para realizar o saque." << endl;
            system("pause");
        } else {
            contas[indiceConta].saldo -= valor;

            system("color 2");
            cout << "\n";
            cout << "--> Saque de R$ " << valor << " realizado com sucesso!" << endl;
            cout << "--> Novo saldo: R$ " << contas[indiceConta].saldo << endl;
            registrar_transacao(contas[indiceConta], "Saque", -valor);
            system("pause");
        }
    }
}
void transferir_valores(Conta contas[], int qtd) {
    system("cls");
    system("color e");

    cout << "-------------------------------------------" << endl;
    cout << "| -------- TRANSFERIR VALORES ------------ |" << endl;
    cout << "-------------------------------------------" << endl << endl;

    char contaOrigem[50];
    char agenciaOrigem[50];
    char contaDestino[50];
    char agenciaDestino[50];
    float valor;


    cout << "--> Digite o número da conta de origem: ";
    cin >> contaOrigem;
    if (!validaNumero(contaOrigem)) {
        cout << "\n";
        cout << system ("color 4");
        cout << "Número inválido!" << endl;
        system ("pause");
        return;
    }
    cout << "--> Digite o número da agência de origem: ";
    cin >> agenciaOrigem;
    if (!validaNumero(agenciaOrigem)) {
        cout << "\n";
        cout << system ("color 4");
        cout << "Número inválido!" << endl;
        system ("pause");
        return;
    }

    int indiceContaOrigem = Buscador(contas, qtd, 1, contaOrigem);
    int indiceAgenciaOrigem = Buscador(contas, qtd, 2, agenciaOrigem);

   
    cout << "--> Digite o número da conta de destino: ";
    cin >> contaDestino;
    if (!validaNumero(contaDestino)) {
        cout << "\n";
        cout << system ("color 4");
        cout << "Número inválido!" << endl;
        system ("pause");
        return;
    }
    cout << "--> Digite o número da agência de destino: ";
    cin >> agenciaDestino;
    if (!validaNumero(agenciaDestino)) {
        cout << "\n";
        cout << system ("color 4");
        cout << "Número inválido!" << endl;
        system ("pause");
        return;
    }

    int indiceContaDestino = Buscador(contas, qtd, 1, contaDestino);
    int indiceAgenciaDestino = Buscador(contas, qtd, 2, agenciaDestino);

    if (indiceContaOrigem == -1 || indiceAgenciaOrigem == -1 || indiceContaDestino == -1 || indiceAgenciaDestino == -1) {
        system("color 4");
        cout << "\n";
        cout << "Conta de origem ou destino não encontrada." << endl;
        cout << "Por favor, verifique os dados informados." << endl;
        system("pause");
    } else {
       
        cout << "\n";
        cout << "------------------- DADOS DA CONTA DE ORIGEM -------------------" << endl;
        cout << "Número da Conta: " << contas[indiceContaOrigem].num_conta << endl;
        cout << "Número da Agência: " << contas[indiceAgenciaOrigem].num_agencia << endl;
        cout << "Nome do titular: " << contas[indiceContaOrigem].nome << endl;
        cout << "CPF do titular: " << contas[indiceAgenciaOrigem].CPF << endl;
        cout << "Saldo atual: R$ " << contas[indiceContaOrigem].saldo << endl << endl;

        cout << "------------------- DADOS DA CONTA DE DESTINO -------------------" << endl;
        cout << "Número da Conta: " << contas[indiceContaDestino].num_conta << endl;
        cout << "Número da Agência: " << contas[indiceAgenciaDestino].num_agencia << endl;
        cout << "Nome do titular: " << contas[indiceContaDestino].nome << endl;
        cout << "CPF do titular: " << contas[indiceAgenciaDestino].CPF << endl;
        cout << "Saldo atual: R$ " << contas[indiceContaDestino].saldo << endl << endl;

        cout << "--> Informe o valor a ser transferido: R$ ";
        cin >> valor;

        if (valor <= 0) {
            system("color 4");
            cout << "\n";
            cout << "Valor inválido! O valor deve ser positivo." << endl;
            system("pause");
        } else if (valor > contas[indiceContaOrigem].saldo) {
            system("color 4");
            cout << "\n";
            cout << "Saldo insuficiente para realizar a transferência." << endl;
            system("pause");
        } else {
    
            contas[indiceContaOrigem].saldo -= valor;
            contas[indiceContaDestino].saldo += valor;

            system("color 2");
            cout << "\n";
            cout << "--> Transferência de R$ " << valor << " realizada com sucesso!" << endl;
            cout << "--> Novo saldo da conta de origem: R$ " << contas[indiceContaOrigem].saldo << endl;
            cout << "--> Novo saldo da conta de destino: R$ " << contas[indiceContaDestino].saldo << endl;
            registrar_transacao(contas[indiceContaOrigem], "Transferência Enviada", -valor);
		    registrar_transacao(contas[indiceContaDestino], "Transferência Recebida", valor);
		
			system("pause");
        }
    }
}

void emitir_extrato(Conta contas[], int qtd) {
    system("cls");
    system("color 7");

    char conta[50];
    char agencia[50];
    int opcao;

    cout << "\n";
    cout << "------------------- EMITIR EXTRATO -------------------" << endl;
    cout << "Escolha uma opção:" << endl;
    cout << "1. Extrato em Tela" << endl;
    cout << "2. Extrato em Arquivo (HTML)" << endl;
    cout << "Opção: ";
    cin >> opcao;

    


    switch (opcao) {
    case 1: {
        system("cls");
        system("color 7");
        
        cout << "--> Digite o número da conta corrente: ";
    	cin >> conta;
        if (!validaNumero(conta)) {
            cout << "\n";
            cout << system ("color 4");
            cout << "Número inválido!" << endl;
            system ("pause");
            return;
        }
    	cout << "--> Digite o número da agência: ";
    	cin >> agencia;
        if (!validaNumero(agencia)) {
            cout << "\n";
            cout << system ("color 4");
            cout << "Número inválido!" << endl;
            system ("pause");
            return;
        }

    	int indiceConta = Buscador(contas, qtd, 1, conta);
    	int indiceAgencia = Buscador(contas, qtd, 2, agencia);

    	if (indiceConta == -1 || indiceAgencia == -1) {
        	cout << "Conta ou agência inválida." << endl;
        	return;
    	}
        
        cout << "---------------- DADOS DA CONTA ----------------" << endl;
        cout << "Número da Conta: " << contas[indiceConta].num_conta << endl;
        cout << "Número da Agência: " << contas[indiceAgencia].num_agencia << endl;
        cout << "Nome do titular: " << contas[indiceConta].nome << endl;
        cout << "CPF do titular: " << contas[indiceAgencia].CPF << endl;
        cout << "Saldo atual: R$ " << contas[indiceConta].saldo << endl << endl;

        cout << "-------------- EXTRATO DE MOVIMENTAÇÕES --------------" << endl;
        for (int i = 0; i < contas[indiceConta].qtd_transacoes; ++i) {
            cout << "Tipo: " << contas[indiceConta].extrato[i].tipo << endl;
            cout << "Valor: R$ " << contas[indiceConta].extrato[i].valor << endl;
            cout << "Saldo: R$ " << contas[indiceConta].extrato[i].saldo_momento << endl;
            cout << "Data: " << contas[indiceConta].extrato[i].data << endl;
            cout << "Hora: " << contas[indiceConta].extrato[i].hora << endl << endl;
        }
        break;
    }
    case 2: {
    	
    	cout << "--> Digite o número da conta corrente: ";
    	cin >> conta;
    	cout << "--> Digite o número da agência: ";
    	cin >> agencia;

    	int indiceConta = Buscador(contas, qtd, 1, conta);
    	int indiceAgencia = Buscador(contas, qtd, 2, agencia);

    	if (indiceConta == -1 || indiceAgencia == -1) {
        	cout << "Conta ou agência inválida." << endl;
        	return;
    	}
    	
        ofstream arquivo("extrato_conta.html");
            if (arquivo.is_open()) {
                arquivo << "<html><head><title>Extrato da Conta</title>" << endl;
				arquivo << "<link rel=\"stylesheet\" href=\"style.css\"> " << endl;
                
arquivo << "<link rel=\"preconnect\" href=\"https://fonts.googleapis.com\">" << endl;
arquivo << "<link rel=\"preconnect\" href=\"https://fonts.gstatic.com\" crossorigin>" << endl;
arquivo << "<link href=\"https://fonts.googleapis.com/css2?family=Inter:wght@400;500;600&display=swap\" rel=\"stylesheet\">" << endl;
arquivo << "<style>" << endl;
arquivo << "body {" << endl;
arquivo << "  font-family: Arial, Helvetica, sans-serif;" << endl;
arquivo << "  background-color: #eee;" << endl;
arquivo << "  display: flex;" << endl;
arquivo << "  justify-content: center;" << endl;
arquivo << "  min-height: 100vh;" << endl;
arquivo << "  font-size: 0.875rem;" << endl;
arquivo << "  font-family: \"Inter\", sans-serif;" << endl;
arquivo << "}" << endl;
arquivo << "*" << endl;
arquivo << "{" << endl;
arquivo << "  margin: 0;" << endl;
arquivo << "  padding: 0;" << endl;
arquivo << "  box-sizing: border-box;" << endl;
arquivo << "}" << endl;
arquivo << ".container {" << endl;
arquivo << "  max-width: 1200px;" << endl;
arquivo << "  width: 100%;" << endl;
arquivo << "  padding: 0 20px;" << endl;
arquivo << "}" << endl;
arquivo << "main {" << endl;
arquivo << "  & h1 {" << endl;
arquivo << "    padding: 30px 0;" << endl;
arquivo << "  }" << endl;
arquivo << "  & h2 {" << endl;
arquivo << "    padding: 20px 0;" << endl;
arquivo << "  }" << endl;
arquivo << "}" << endl;
arquivo << ".user-wrapper {" << endl;
arquivo << "  display: flex;" << endl;
arquivo << "  gap: 32px;" << endl;
arquivo << "  align-items: center;" << endl;
arquivo << "  padding: 14px;" << endl;
arquivo << "  width: 100%;" << endl;
arquivo << "  max-width: 100%;" << endl;
arquivo << "  background-color: #fff;" << endl;
arquivo << "  box-shadow: 0 1px 3px 0 rgba(0, 0, 0, 0.1), 0 1px 2px -1px rgba(0, 0, 0, 0.1);" << endl;
arquivo << "  border-radius: 8px;" << endl;
arquivo << "  & .user-img {" << endl;
arquivo << "    background-color: #dfe7f6;" << endl;
arquivo << "    margin-left: 12px;" << endl;
arquivo << "    border-radius: 50%;" << endl;
arquivo << "  }" << endl;
arquivo << "  & .user-data {" << endl;
arquivo << "    & p {" << endl;
arquivo << "      font-weight: 600;" << endl;
arquivo << "    }" << endl;
arquivo << "    & p + p {" << endl;
arquivo << "      margin-top: 6px;" << endl;
arquivo << "    }" << endl;
arquivo << "    & span {" << endl;
arquivo << "      font-weight: 400;" << endl;
arquivo << "    }" << endl;
arquivo << "  }" << endl;
arquivo << "}" << endl;
arquivo << ".table-data {" << endl;
arquivo << "  padding: 20px;" << endl;
arquivo << "  background-color: #fff;" << endl;
arquivo << "  box-shadow: 0 1px 3px 0 rgba(0, 0, 0, 0.1), 0 1px 2px -1px rgba(0, 0, 0, 0.1);" << endl;
arquivo << "  border-radius: 8px;" << endl;
arquivo << "  & .deposit," << endl;
arquivo << "  .withdrawal {" << endl;
arquivo << "    font-size: 12px;" << endl;
arquivo << "    padding: 2px 10px;" << endl;
arquivo << "    border-radius: 100px;" << endl;
arquivo << "    font-weight: 500;" << endl;
arquivo << "    text-align: center;" << endl;
arquivo << "  }" << endl;
arquivo << "  & .deposit {" << endl;
arquivo << "    border: 1px solid #0d6832;" << endl;
arquivo << "    background-color: #d6f0e0;" << endl;
arquivo << "    color: #0d6832;" << endl;
arquivo << "  }" << endl;
arquivo << "  & .withdrawal {" << endl;
arquivo << "    border: 1px solid #a61001;" << endl;
arquivo << "    background-color: #ffebe9;" << endl;
arquivo << "    color: #a61001;" << endl;
arquivo << "  }" << endl;
arquivo << "  & table {" << endl;
arquivo << "    width: 100%;" << endl;
arquivo << "    text-align: center;" << endl;
arquivo << "    & th {" << endl;
arquivo << "      padding: 12px 0;" << endl;
arquivo << "      border-bottom: 1px solid #ddd;" << endl;
arquivo << "      font-weight: 600;" << endl;
arquivo << "    }" << endl;
arquivo << "    & td {" << endl;
arquivo << "      padding: 10px 0;" << endl;
arquivo << "      border-bottom: 1px solid #eee;" << endl;
arquivo << "    }" << endl;
arquivo << "    & tbody tr:last-child td {" << endl;
arquivo << "      border-bottom: none;" << endl;
arquivo << "    }" << endl;
arquivo << "  }" << endl;
arquivo << "}" << endl;
arquivo << "</style>" << endl;
arquivo << "</head>" << endl;
arquivo << "<body>" << endl;
arquivo << "<div class=\"container\">" << endl;
arquivo << "<main>" << endl;
arquivo << "<h1>Extrato bancário</h1>" << endl;
arquivo << "<section class=\"user-wrapper\">" << endl;
arquivo << "<img class=\"user-img\" src=\"./user.svg\" width=\"50\" height=\"50\" alt=\"icone de um usuário\">" << endl;
arquivo << "<div class=\"user-data\">" << endl;
arquivo << "<p>Nome: <span>" << contas[indiceConta].nome << "</span></p>" << endl;
arquivo << "<p>Agência: <span>" << contas[indiceConta].num_conta << "<span></p>" << endl;
arquivo << "<p>Conta: <span>" << contas[indiceConta].num_conta << "</span></p>" << endl;
arquivo << "<p>CPF: <span>" << contas[indiceAgencia].CPF << "</span></p>" << endl;
arquivo << "<p> Saldo: <span>" << contas[indiceConta].saldo << "</span></p>" << endl;
arquivo << "</div>" << endl;
arquivo << "</section>" << endl;
arquivo << "<h2>Histórico de Movimentações</h2>" << endl;
arquivo << "<section class=\"table-data\">" << endl;
arquivo << "<table>" << endl;
arquivo << "<thead>" << endl;
arquivo << "<tr>" << endl;
arquivo << "<th>Data</th>" << endl;
arquivo << "<th>Hora</th>" << endl;
arquivo << "<th>Lançamento</th>" << endl;
arquivo << "<th>Valor</th>" << endl;
arquivo << "<th>Saldo</th>" << endl;
                arquivo << "</tr>" << endl;
                arquivo << "</thead>" << endl;
                arquivo << "<tbody>" << endl;

            
                for (int i = 0; i < contas[indiceConta].qtd_transacoes; i++) {
                    arquivo << "<tr>" << endl;
                    arquivo << "<td>" << contas[indiceConta].extrato[i].data << "</td>" << endl;
                    arquivo << "<td>" << contas[indiceConta].extrato[i].hora << "</td>" << endl;
                    arquivo << "<td><span class=\"";
                    
                    
                    if (strcmp(contas[indiceConta].extrato[i].tipo, "Depósito") == 0) {
                        arquivo << "deposit\">Depósito</span></td>" << endl;
                    } else if (strcmp(contas[indiceConta].extrato[i].tipo, "Saque") == 0) {
                        arquivo << "withdrawal\">Saque</span></td>" << endl;
                    } else if (strcmp(contas[indiceConta].extrato[i].tipo, "Transferência") == 0) {
                        arquivo << "withdrawal\">Transferência</span></td>" << endl;
                    } else if ((strcmp(contas[indiceConta].extrato[i].tipo, "Transferência Enviada") == 0)) {
                    	arquivo << "withdrawal\">Transferência enviada</span></td>" << endl;
					} else if ((strcmp(contas[indiceConta].extrato[i].tipo, "Transferência Recebida") == 0)) {
                    	arquivo << "deposit\">Transferência recebida</span></td>" << endl;
					}
					
					else {
                        arquivo << "\">" << contas[indiceConta].extrato[i].tipo << "</span></td>" << endl;
                    }

                    arquivo << "<td>R$ " << contas[indiceConta].extrato[i].valor << "</td>" << endl;
                    arquivo << "<td>R$ " << contas[indiceConta].extrato[i].saldo_momento << "</td>" << endl;
                    arquivo << "</tr>" << endl;
                }

                arquivo << "</tbody>" << endl;
                arquivo << "</table>" << endl;
                arquivo << "</section>" << endl;
                arquivo << "</main></div></body></html>" << endl;
                arquivo.close();

                cout << "\n\nExtrato salvo em extrato_conta.html" << endl;
            } else {
                cout << "\nErro ao criar o arquivo." << endl;
            }
            break;
        }
    	default: {
       		cout << "Opção inválida." << endl;
        break;
    	}
        system("pause");
	}
    
    system("pause");
}


void registrar_transacao(Conta& conta, const char* tipo, float valor) {
   

    Transacao nova_transacao;
    strcpy(nova_transacao.tipo, tipo);
    nova_transacao.valor = valor;

   float saldo_momento = conta.saldo;
   
    time_t agora = time(0); 
    strftime(nova_transacao.data, sizeof(nova_transacao.data), "%d/%m/%Y", localtime(&agora)); 
	strftime(nova_transacao.hora, sizeof(nova_transacao.hora), "%H:%M", localtime(&agora)); 
    nova_transacao.saldo_momento = saldo_momento;

    conta.extrato[conta.qtd_transacoes++] = nova_transacao;
}
bool cpfValido(char cpf[11]) {
    int i, j, digit, d1, d2;
    char temp[11];

    for (i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            return false;
        }
        temp[i] = cpf[i] - '0';
    }

    for (i = 0, j = 10, d1 = 0; i < 9; i++, j--) {
        d1 += temp[i] * j;
    }
    d1 = 11 - (d1 % 11);
    if (d1 > 9) d1 = 0;

    for (i = 0, j = 11, d2 = 0; i < 10; i++, j--) {
        d2 += temp[i] * j;
    }
    d2 = 11 - (d2 % 11);
    if (d2 > 9) d2 = 0;

    return d1 == temp[9] && d2 == temp[10];
}

bool validaNome(char nome[]) {
    int len = strlen(nome);
    if (len < 3) {
        return false;
    }

    for(int i = 0; i < len; i++) {
        if (!isalpha(nome[i]) && nome[i] != ' ') {
            return false;
        }
    }

    return true;
}

bool validaNumero(char numero[]) {
    for(int i = 0; i < strlen(numero); i++) {
        if (!isdigit(numero[i])) {
            return false;
        }
    }

    return true;
}