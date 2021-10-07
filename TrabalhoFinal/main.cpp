#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "ContaComum.h"
#include "ContaLimite.h"
#include "ContaPoupanca.h"
#include "Conta.h"
#include "PessoaFisica.h"
#include "PessoaJuridica.h"
#include "Pessoa.h"
#include "Banco.h"

#include <vector>
using std::vector;

int clienteCadastrado(Banco &banco, string nome){
    if(banco.achaCorrentista(nome).getNome() == nome){
        return 1;
    }else{
        return 0;
    }
}

void cadastrarCliente(Banco &banco, string nome){
    int tipo;
    cout << "Deseja cadastrar como Pessoa Física ( 1 ) ou Juridica ( 2 )?";
    cin >> tipo;

    if (tipo == 1){
        long int cpf;

        cout << "Digite seu cpf: ";
        cin >> cpf;

        PessoaFisica novaPessoa(nome,cpf);
        banco.cadastrarCorrentista(novaPessoa);
    }else if(tipo == 2){

        long int cnpj;
        string razao;

        cout << "Digite seu CNPJ: ";
        cin >> cnpj;

        cout << "Digite sua razão social: ";
        cin >> razao;

        PessoaJuridica novaPessoa(nome,cnpj,razao);
        banco.cadastrarCorrentista(novaPessoa);
    }
}

void gerenciarBanco(Banco &banco){
    while(true){
    int opcao = 0;
    cout << "======== Conta Gerente ========\n";
    cout << "Abrir conta( 1 ), Consultar Conta ( 2 )\n";
    cout << "Atualizar Conta ( 3 ), Fechar Conta ( 4 )\n";
    cout << "Digite uma operação: ";
    cin >> opcao;
    cout << "===============================\n";

    if(opcao == 1){
        string correntista;
        cout << "Digite o nome do correntista: ";
        cin >> correntista;
        int existe = clienteCadastrado(banco,correntista);

        if(existe == 0){
            cout << "Cliente Não Cadastrado!\n";
            cadastrarCliente(banco, correntista);
        }

        string tipo;
        long int num;
        double valor;
        int aniver = 0;
        double limite = 0;

        cout << "Digite o tipo da conta nova (comum, limite ou poupanca): ";
        cin >> tipo;
        cout << "Digite o número da conta: ";
        cin >> num;
        cout << "Digite o valor inicial da conta: ";
        cin >> valor;

        if(tipo == "poupanca"){
            cout << "Digite o aniversário da conta: ";
            cin >> aniver;
            ContaPoupanca novaConta(num, banco.achaCorrentista(correntista), valor, aniver);
            banco.cadastrarConta(novaConta);

        }else if (tipo == "limite"){
            cout << "Digite o limite inicial da conta: ";
            cin >> limite;
            ContaLimite novaConta(num, banco.achaCorrentista(correntista), valor, limite);
            banco.cadastrarConta(novaConta);

        }else{
            ContaComum novaConta(num, banco.achaCorrentista(correntista), valor);
            banco.cadastrarConta(novaConta);
        }

    }else if(opcao == 2){
        long int num;
        cout << "Digite o número da conta: ";
        cin >> num;

        banco.consultarConta(num);
    }else if(opcao == 3){
        long int num;
        cout << "Digite o número da conta: ";
        cin >> num;

        int tipoConta;
        cout << "Digite o novo tipo de conta que deseja: Comum ( 1 ), Limite ( 2 ) ou Poupanca ( 3 ): ";
        cin >> tipoConta;

        banco.atualizarConta(banco.achaConta(num), tipoConta);

    }else if(opcao == 4){
        long int num;
        cout << "Digite o número da conta: ";
        cin >> num;

        banco.removerConta(num);

    }else{
        break;
    }
    }
}

void gerenciarConta(Banco & banco, long int conta){

}

int main(){
    Banco banco("BIF", 5123125, "Banco do IF");
    int operacao = 0;

    cout << "=================  Banco BIF   ===============\n" ;
    cout << "Deseja entrar como gerente ( 1 ) ou correntista? ( 2 ): " ;
    cin >> operacao;
    cout << "==============================================\n" << endl;

    if(operacao == 1){
        gerenciarBanco(banco);
    }else if(operacao == 2){
        long int conta;
        cout << "Digite o número de sua conta: ";
        cin >> conta;

        for(int i = 0; i < banco.getNum(); i ++){

        }
    }
    
    return 0;
}
