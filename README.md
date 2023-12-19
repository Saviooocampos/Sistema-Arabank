# Documentação do Código

## Descrição

Programa para gerenciar contas correntes em um banco.
Este programa permite cadastrar, alterar, excluir, consultar saldo, realizar depósito, realizar saque, transferir valores, emitir extrato e mostrar todas as contas correntes de um banco. Os dados das contas são armazenados em um arquivo binário para persistência. O programa utiliza structs para representar as contas correntes e as transações realizadas.

## Funções

`void menu (int &opcao)`

Exibe o menu principal do sistema. A opção escolhida pelo usuário é armazenada na variável `opcao`.

`int Buscador (Conta contas [], int qtd, int escolha, char busca [])`

Busca uma conta corrente no vetor de contas. Retorna o índice da conta encontrada ou -1 se não encontrada.

`void cadastrar_conta (Conta contas [], int &qtd)`

Cadastra uma nova conta corrente no vetor de contas.

`int salvaDados (Conta contas [],int qtd)`

Salva os dados das contas correntes em um arquivo binário. Retorna 0 em caso de erro na criação do arquivo, 1 caso contrário.

`void LeDados (Conta contas [], int &qtd)`

Lê os dados das contas correntes de um arquivo binário.

`void alterar_conta ( Conta contas[],int qtd )`

Altera os dados de uma conta corrente.

`void excluir_conta (Conta contas [],int &qtd)`

Exclui uma conta corrente.

`void mostraTodas (Conta contas [],int qtd)`

Exibe todas as contas correntes e seus saldos.

`void consultaSaldo (Conta contas [], int qtd)`

Consulta o saldo de uma conta corrente.

`void realizar_deposito(Conta contas[], int qtd)`

Realiza um depósito em uma conta corrente.

`void realizar_saque(Conta contas[], int qtd)`

Realiza um saque em uma conta corrente.

`void transferir_valores(Conta contas[], int qtd)`

Transfere valores entre duas contas correntes.

`void registrar_transacao(Conta& conta, const char* tipo, float valor)`

Registra uma transação em uma conta corrente.

`void emitir_extrato(Conta contas[], int qtd)`

Emite o extrato de uma conta corrente.

`bool cpfValido(char cpf[11])`

Verifica se um CPF é válido. Retorna true se o CPF é válido, false caso contrário.

`bool validaNome(char nome[])`

Verifica se um nome é válido. Retorna true se o nome é válido, false caso contrário.

`bool validaNumero(char numero[])`

Verifica se um número é válido. Retorna true se o número é válido, false caso contrário.
