#include "Banco.h"
#include "ContaComum.h"
#include "ContaLimite.h"
#include "ContaPoupanca.h"

#include <iostream>
using std::cout;
using std::endl;

Banco::Banco(string nome, long int CNPJ, string razao) : PessoaJuridica(nome, CNPJ, razao){
    this->nome = nome;
    this->cnpj = CNPJ;
    this->razao = razao;
}

void Banco::cadastrarConta(Conta & conta){
    this->contas.push_back(conta);
    this->numContas ++;
}

void Banco::removerConta(long int num){
    for(int i = 0; i < numContas; i++){
        if(this->contas[i].getNumero() == num){
            this->contas.erase(contas.begin() + i);
        }
    }
}

void Banco::consultarConta(long int num){
    for(int i = 0; i < numContas; i++){
        if(this->contas[i].getNumero() == num){
            this->contas[i].extrato();
        }
    }
}

void Banco::atualizarConta(long int num, Pessoa &novoDono, string tipoConta, double novoValor, int x = 0 ){
    this->removerConta(num);
    if(tipoConta == "comum"){
        ContaComum novaConta(num,novoDono,novoValor);
        this->contas.push_back(novaConta);
        this->numContas ++;

    }else if(tipoConta == "poupanca"){
        ContaPoupanca novaConta(num,novoDono,novoValor, x);
        this->contas.push_back(novaConta);
        this->numContas ++;

    }else if(tipoConta == "limite"){
        ContaLimite novaConta(num, novoDono, novoValor, 500.00);
        this->contas.push_back(novaConta);
        this->numContas ++;
    }
}

void Banco::listarContas(){
    for(int i = 0; i < this-> numContas; i++){
        cout << "\n============ Conta ============\n";
        cout << "Nome do Correntista: " << contas[i].getCorrentista().getNome() << endl;
        cout << "Número da conta: " << contas[i].getNumero() << endl;
        cout << "Saldo: $" << contas[i].getSaldo() << endl;
        cout << "===============================" << endl;
    }
}

void Banco::listarContasCorrentista(Pessoa &pessoa){
    for(int i = 0; i < this-> numContas; i++){
        if(contas[i].getCorrentista().getNome() == pessoa.getNome()){
        cout << "\n============ Conta ============\n";
        cout << "Nome do Correntista: " << contas[i].getCorrentista().getNome() << endl;
        cout << "Número da conta: " << contas[i].getNumero() << endl;
        cout << "Saldo: $" << contas[i].getSaldo() << endl;
        cout << "===============================" << endl;
        }
    }
}
