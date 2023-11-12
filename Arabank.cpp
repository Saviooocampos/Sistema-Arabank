#include <iostream>
#include <locale.h>
using namespace std;

// constante do tamanho do vetor struct
const int QTD_MAX = 2;

struct Conta {
    char num_conta [10];
    char num_agencia [10];
    char nome [20];
    char CPF [20];
    float saldo;
};

void menu (int &opcao);
void castrar_conta (Conta contas [], int &qtd);

int main (){
    // mostrar caracteres especiais 
    setlocale(LC_ALL, "Portuguese");
    
    // vetor struct
    Conta contas [QTD_MAX];

    Conta c;

    int qtd = 0;

    int op;

    do {
        system ("cls");
        menu (op);
        
        switch (op) {
            case 1: 
                // cadastrar conta corrente 
                castrar_conta (contas,qtd);

                break;
            case 2:
                // alterar dados da conta corrente
                break;
            case 3:
                // excluir conta 
                break;
            case 4:
                // consultar saldo
                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
            case 8:

                break;
            case 9:

                break;
            case 10:
                cout << "Sistema finalizado com sucesso " << endl;
                break;
            default:
                cout << "--* Opcao Invalida *-- " << endl;
                cout << "Escolha uma opcao entre 1 e 10 " << endl;
                system ("pause");
                break;
        }
    

    } while (op != 10); 
    

    return 0;
}


void menu (int &opcao){
   
    cout << "\t ******************************* " << endl;
    cout << "\t  * ARABANCO - SEMPRE COM VOCÊ !! * " << endl;
    cout << "\t ******************************* " << endl << endl;

    cout << "------------------ MENU -----------------------\n" << endl; 
    cout << "1.) Cadastrar conta corrente. " << endl;
    cout << "2.) Alterar dados de uma conta corrente" << endl;
    cout << "3.) Excluir uma conta corrente" << endl;
    cout << "4.) Consultar saldo" << endl;
    cout << "5.) Fazer depósito" << endl;
    cout << "6.) Realizar saque" << endl;
    cout << "7.) Transeferir valores" << endl;
    cout << "8.) Mostrar todas as contas e saldos" << endl;
    cout << "9.) Emitir extrato de conta " << endl;
    cout << "10.) Sair" << endl;
    cout << "----------------------------------------------- \n"<< endl << endl;
    cout << "Escolha uma opção: " ;
    cin >> opcao;

}

void castrar_conta (Conta contas [], int &qtd){
    system ("cls");

    Conta c;

    cout << "\t **************************" << endl;
    cout << "\t * CRIAR CONTA CORRENTE * " << endl;
    cout << "\t ************************* " << endl << endl;

    if (qtd >= QTD_MAX){
        cout << "ERRO ! "<< endl;
        cout << "Agenda cheia";
        system("pause");
        return;
    }

    cout << "Insira o numero da conta " << endl;
    cin >> c.num_conta;
    cout << "Insira o número da agência" << endl;
    cin >> c.num_agencia;
    cout << "Insira o nome do titular " << endl;
    cin >> c.nome;
    cout << "insira o CPF do titular" << endl;
    cin >> c.CPF;
    cout << "Qual é o saldo inicial ? " << endl;
    cin >> c.saldo;

    if (c.saldo < 0 ){
        cout << "\t Saldo insuficiente !! " << endl;
        cout << "O seu saldo não pode ser negativo para a criação da conta ";
        system ("pause");
        return;
    }

    contas [qtd++] = c;

    cout << "A conta foi criada com sucesso ! ";

    system ("pause");
}