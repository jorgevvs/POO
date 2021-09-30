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

void Banco::cadastrarConta(Pessoa &novaPessoa, string tipoConta, long int numero, double valorInicial, int x = 0){
    this->correntistas.push_back(novaPessoa);
    if(tipoConta == "comum"){
        ContaComum novaConta(numero,novaPessoa,valorInicial);
        this->contas.push_back(novaConta);
        this->numContas ++;

    }else if(tipoConta == "poupanca"){
        ContaPoupanca novaConta(numero,novaPessoa,valorInicial, x);
        this->contas.push_back(novaConta);
        this->numContas ++;

    }else if(tipoConta == "limite"){
        ContaLimite novaConta(numero, novaPessoa, valorInicial, 500.00);
        this->contas.push_back(novaConta);
        this->numContas ++;
    }
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
    for(int i = 0; i < this->numContas; i++){
        contas[i].extrato();
    }
}

void Banco::listarContasCorrentista(Pessoa &pessoa){
    for(int i = 0; i < this->numContas;i++){
        if(contas[i].getCorrentista().getNome() == pessoa.getNome()){
            contas[i].extrato();
        }
    }
}
