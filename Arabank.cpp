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
void mostraTodas (Conta contas [],int qtd);
void consultaSaldo (Conta contas [], int qtd);
void Deposito (Conta contas [],int qtd);
void Saque (Conta contas [],int qtd);

////////////////////////////////////////////////////////

int main (){
    // mostrar caracteres especiais no terminal
    setlocale(LC_ALL, "portuguese");
    
    // vetor struct
    Conta contas [QTD_MAX];
    //Conta c;

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
        		Deposito (contas,qtd);
                break;
            case 6:
                //Realizar saque
                Saque (contas,qtd);
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
////// Menu Principal ///////
////////
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
	cout << "| 10.)\t Sair" << endl << endl;
    cout << "----------------------------------------------- \n"<< endl << endl;
    cout << "------> Escolha uma opção: " ;
    cin >> opcao;

}
/////////////////////////////////
// --------------------/
// Usada constantemente
// ---------------------
//  Valores para 'escolha': 
//	1 = Buscar Número da Conta
//	2 = Buscar Número da Agência
//	3 = Buscar Nome 
//	4 = Buscar CPF do Titular
//	
/////////////////////////////////////////

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

///// Gera o arquivo que armazena as informações do struct ao sair do programa 
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
    bool valido;
    
    cout << "Insira um Número de Conta Corrente: ";
    cin >> conta;
    cout << "Insira a Agência da Conta Corrente:";
    cin >> agencia;
   
    int BuscaConta = Buscador (contas,qtd,1,conta);
    int BuscaAgencia = Buscador (contas,qtd,2,agencia);
    
    valido = ( BuscaConta == BuscaAgencia ) && BuscaConta != -1 && BuscaAgencia != -1;
    
    // Se válido, então
    if (valido){
        system ("color 2");
        cout << "\n";
        int indice = BuscaAgencia;
        cout << " -- Digite os dados da nova conta -- " << endl << endl;
        cout << "Nome do titular: ";
        cin >> contas[indice].nome;
        cout << "\n";
        cout << "CPF do titular: ";
        cin >> contas[indice].CPF;
        cout << "\n";
        cout << "Conta alterada !!!" << endl << endl;
        system ("pause");
    }
    else {
		cout << "\n";
        cout << system ("color 4");
        cout << "Atenção !" << endl;
        cout << "Conta ou Agência inválida " << endl;
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
    bool valido;
    
    cout << "Insira um Número de Conta Corrente: ";
    cin >> conta;
    cout << "\n";
    cout << "Insira a Agência da Conta Corrente: ";
    cin >> agencia;

    int BuscaConta = Buscador (contas,qtd,1,conta);
    int BuscaAgencia = Buscador (contas,qtd,2,agencia);
    
    valido = BuscaConta == BuscaAgencia && BuscaConta != -1;

    if (valido){
        for (int i = BuscaConta; i < qtd - 1;i++){
            contas [i] = contas [i+1];
        }
        qtd--;
        system ("color b");
        cout << "\n";
        cout << "---> Conta Excluida !!" << endl;
        system ("pause");
    }
    else {
	    system ("color 4");
        cout << "Atenção !" << endl;
        cout << "Conta ou Agência inválida ";
        system ("pause");
    }
}

void mostraTodas (Conta contas [],int qtd){ 
    system ("cls");
    system ("color 5");
    cout << "\n";
    cout << "\t******************************************************************************* " << endl;
    cout << "\t*------------------------ TODAS AS CONTAS E SALDOS ---------------------------* " << endl;
    cout << "\t*******************************************************************************" << endl << endl;

    for (int i = 0; i < qtd; i++){
        cout << " CONTA: " << contas[i].num_conta << "\t\t" 
		<< "AGÊNCIA:" << contas[i].num_agencia << "\t\t"
        << "NOME: " << contas[i].nome << "\t\t" 
        << "CPF: " << contas[i].CPF << "\t\t" 
        << "SALDO: " << contas[i].saldo << "\t\t" <<"\n\n";   
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
    bool valido;
	     
    cout << "--> Digite o número da conta corrente: ";
    cin >> conta;
    cout << "--> Digite o número da agência:  ";
    cin >> agencia;
    
    int BuscaConta = Buscador (contas,qtd,1,conta);
    int BuscaAgencia = Buscador (contas,qtd,2,agencia);

	valido = BuscaConta == BuscaAgencia && BuscaAgencia != -1;
    
    if (valido){
		int indice = Buscador (contas,qtd,2,agencia);
		system ("cls");
		system ("color d");
		cout << "\n";
		cout << "-------------------------------------------" << endl;
		cout << "| ------------ SALDO --------------------- |" << endl;
		cout << "-------------------------------------------" << endl << endl;
		
		cout << "--> Usuário: " << contas[indice].nome << endl;
		cout << "--> Saldo atual: " << "R$ " << contas[indice].saldo << endl; 
		
		system ("pause");
    }
    else {
        system ("color 4");
        cout << "\n";
        cout << "Atenção !" << endl;
        cout << "Conta ou Agência inválida" << endl;
        system ("pause");
    }

}

void Deposito (Conta contas [],int qtd){
	
	char conta [50];
    char agencia [50];
    bool valido;	

	// a repete o processo até o depósito ser bem-sucedido 
	do {
        system ("cls");
        system ("color e");
        
        cout << "\n";
    	cout << " ******************************************************* " << endl;
    	cout << " * -----------------  Depósito ----------------------- * " << endl;
    	cout << " ******************************************************* " << endl << endl;
    	
        cout << "--> Digite o número da conta corrente: ";
        cin >> conta;
        cout << "--> Digite o número da agência:  ";
        cin >> agencia;
        
        int BuscaConta = Buscador (contas,qtd,1,conta);
    	int BuscaAgencia = Buscador (contas,qtd,2,agencia);
    
    	// a busca é valida quando
		valido = BuscaConta == BuscaAgencia && BuscaAgencia != -1;
        // conta e agência possuem o mesmo indice e ambas retornam um valor diferente de -1

        
        int indice = BuscaAgencia;
		     
        if (valido){
            system ("cls");
            system ("color 2");
        
            cout << "\n";
		    cout << "------------------------------------------ DADOS DA CONTA --------------------------------------------" << endl << endl;
		    cout << "\t\t" << "Numero da conta: " << contas[indice].num_conta  << "\t" 
		    << " Agência: " << contas[indice].num_agencia << "\t" 
		    <<  " NOME: " << contas[indice].nome << "\t" 
		    << " CPF: " << contas[indice].CPF << "\t" << endl << endl;
		    cout << "------------------------------------------------------------------------------------------------------" << endl;
		    cout << "\n";
        
            cout << "--> Saldo atual:  " << contas[indice].saldo << endl;
            float deposito;
            float saldo;
            cout << "---> Qual o valor do depósito ? ";
            cin >> deposito;
            
            while (deposito <= 0){
            	system ("color 4");
                cout << "\n";
                cout << "---------------------------------------------------------------------" << endl;
                cout << "\t ATENÇÃO !!!" << endl;
                cout << "É impossível fazer um depósito se a quantia for menor ou igual a zero " << endl << endl;
                cout << "----> Digite novamente: ";
            	cin >> deposito;
            	cout << "\n";
			}
            
			// impossível sacar valores menores ou iguais a zero
            if (deposito > 0 ){
            	system ("color 2");
            	system ("cls");
            	cout << "\n";
			    cout << "------------------------------------------ DADOS DA CONTA --------------------------------------------" << endl << endl;
			    cout << "\t\t" << "Numero da conta: " << contas[indice].num_conta  << "\t" 
			    << " Agência: " << contas[indice].num_agencia << "\t" 
			    <<  " NOME: " << contas[indice].nome << "\t" 
			    << " CPF: " << contas[indice].CPF << "\t" << endl << endl;
			    cout << "------------------------------------------------------------------------------------------------------" << endl;
			    cout << "\n";
                saldo = contas[indice].saldo + deposito; 
                contas[indice].saldo = saldo;
                cout << "*************************************************" << endl;
                cout << "\tDepósito concluido !!" << endl;
                cout << "------> Saldo após o depósito: " << "R$ " << contas[indice].saldo << endl;
                cout << "*************************************************" << endl << endl;
                system ("pause"); 
            }
        }
        else {
			system ("color 4");
            cout << "\n";
            cout << "Atenção !" << endl;
            cout << "Conta ou Agência inválida " << endl << endl;
            system ("pause");		 
        }
    } while (!valido);
    
}

void Saque (Conta contas [],int qtd){
	
	char conta [50];
    char agencia [50];
    bool valido;

    // repete o processo até o depósito ser bem-sucedido 
    do {
    	system ("cls");
        system ("color e");
        cout << "\n";
    	cout << " ******************************************************* " << endl;
    	cout << " * -------------------  Saque ------------------------ * " << endl;
    	cout << " ******************************************************* " << endl << endl;
    
		cout << "--> Digite o número da conta corrente: ";
    	cin >> conta;
    	cout << "--> Digite o número da agência:  ";
    	cin >> agencia;
    	
    	int BuscaConta = Buscador (contas,qtd,1,conta);
    	int BuscaAgencia = Buscador (contas,qtd,2,agencia);
    	
    	// a busca é valida quando 
    	valido = BuscaConta == BuscaAgencia && BuscaAgencia != -1;
        // busca conta e agência possuem o mesmo indice e ambas retornam um valor diferente de -1

        int indice = BuscaAgencia;
    	
    	if (valido){
    		system ("cls");
            system ("color 2");
			
			//passamos o retorno da busca para o indice
    		float saque;
			float saldo;
    		
            cout << "\n";
		    cout << "------------------------------------------ DADOS DA CONTA --------------------------------------------" << endl << endl;
		    cout << "\t\t" << "Numero da conta: " << contas[indice].num_conta  << "\t" 
		    << " Agência: " << contas[indice].num_agencia << "\t" 
		    <<  " NOME: " << contas[indice].nome << "\t" 
		    << " CPF: " << contas[indice].CPF << "\t" << endl << endl;
		    cout << "------------------------------------------------------------------------------------------------------" << endl;
		    cout << "\n";
		    cout << "--> Saldo atual:  " << contas[indice].saldo << endl;
		    cout << "---> Qual o valor do saque ? ";
			cin >> saque;
			
			while (saque <= 0 || saque > contas[indice].saldo){
				system ("color 4");
				cout << "\n";
				cout << "-----------------------------------------------------------" << endl;
				cout << "\t  ATENÇÃO !!! " << endl << endl;
				cout << "É impossível sacar uma quantia se" << endl;
				cout << "-> a quantia for menor ou igual a zero" << endl;
				cout << "-> a quantia for maior do que o valor disponível na conta "<< endl << endl;
				cout << "----> Digite novamente: ";
            	cin >> saque;
            	cout << "\n";

			}
			
			if (saque > 0 && saque <= contas[indice].saldo ){
				system ("color 2");
				system ("cls");
            	cout << "\n";
			    cout << "------------------------------------------ DADOS DA CONTA --------------------------------------------" << endl << endl;
			    cout << "\t\t" << "Numero da conta: " << contas[indice].num_conta  << "\t" 
			    << " Agência: " << contas[indice].num_agencia << "\t" 
			    <<  " NOME: " << contas[indice].nome << "\t" 
			    << " CPF: " << contas[indice].CPF << "\t" << endl << endl;
			    cout << "------------------------------------------------------------------------------------------------------" << endl;
			    cout << "\n";
                saldo = contas[indice].saldo - saque; 
                contas[indice].saldo = saldo;
                cout << "\n";
                cout << "*************************************************" << endl;
                cout << "\tTransação concluida !!" << endl;
				cout << "-----> Saldo após o saque: " << "R$ " << contas[indice].saldo << endl;
				cout << "*************************************************" << endl << endl;
                system ("pause");	
			}
		}
		else {
		system ("color 4");
    	cout << "\n";
    	cout << "Atenção !" << endl;
		cout << "Conta ou Agência inválida " << endl;
    	system ("pause");
		}	

	} while(!valido);
	
}
