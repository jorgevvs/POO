#include "Banco.h"
#include "ContaComum.h"
#include "ContaLimite.h"
#include "ContaPoupanca.h"
#include "PessoaFisica.h"
#include "PessoaJuridica.h"


#include <iomanip>
using std::setw;

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios;

#include <iostream>
using std::cout;
using std::endl;

Banco::Banco(string nome, long int CNPJ, string razao) : PessoaJuridica(nome, CNPJ, razao){
    this->nome = nome;
    this->cpfOrCNPJ = CNPJ;
    this->razao = razao;

    this->ler_dados();
}

void Banco::cadastrarConta(Conta & conta){
    int correntistaExiste = 0;
    for(int i = 0; i < numCorrentistas; i++){
        if(correntistas[i].getNome() == conta.getCorrentista().getNome()) correntistaExiste = 1;
    }

    if(correntistaExiste == 0){
        this->correntistas.push_back(conta.getCorrentista());
        this->numCorrentistas ++;
    }
    int contaExiste = 0;

    for(int i = 0; i < numContas; i++){
        if(conta.getNumero() == contas[i].getNumero()) contaExiste = 1;
    }

    if(contaExiste == 0){
        this->contas.push_back(conta);
        this->numContas ++;
    }
    
}

void Banco::removerConta(long int num){
    int aux = 0;
    for(int i = 0; i < numContas; i++){
        if(this->contas[i].getNumero() == num){
            this->contas.erase(contas.begin() + i);

            for(int j = 0; j < numContas; j++){
                if(contas[i].getCorrentista().getNome() == contas[j].getCorrentista().getNome()){
                    aux ++;
                }
            }
            if(aux == 1){
                for(int j = 0; j < numCorrentistas; j ++){
                    if(this->correntistas[j].getNome() == contas[i].getCorrentista().getNome()){
                        this->correntistas.erase(correntistas.begin() + j);
                        numCorrentistas --;
                    }
                }
            }
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

bool Banco::salvar_dados(){
  ofstream fout("contas.dat", std::ios::out);

  if (!fout)
    return false;
  
  for (int i = 0 ; i < numContas ; i++){
    fout <<  contas[i].getNumero() <<' ' << contas[i].getCorrentista().getNome() << ' ' << contas[i].getSaldo() << " "<< contas[i].getAniver() << " " << contas[i].getLimite() <<endl;
  }

  fout.close(); 

  salva_pessoas();

  return true;
}

bool Banco::salva_pessoas(){
    ofstream fout("correntistas.dat", std::ios::out);

  if (!fout)
    return false;
  
  for (int i = 0 ; i <  numCorrentistas; i++){
    fout << correntistas[i].getNome() << ' ' << correntistas[i].getCpfOrCNPJ() << ' ' << correntistas[i].getRazao() << endl;
  }

    fout.close(); 

    return true;
}


struct Conta_entrada{
    string nome;
    long int num;
    double saldo;
    int aniver;
    double limite;
};

struct correntistas_entrada{
    string nome;
    long int cpfOrCNPJ;
    string razao;
};

bool Banco::ler_dados(){
  ifstream fin("correntistas.dat", std::ios::in);

  if (!fin) return false;

    correntistas_entrada c;

    while (fin >> c.nome >> c.cpfOrCNPJ >> c.razao){   
        if(c.razao != "x"){
            PessoaJuridica novaPessoa(c.nome, c.cpfOrCNPJ, c.razao);
            this->correntistas.push_back(novaPessoa);
            this->numCorrentistas ++;
        }else{
            PessoaFisica novaPessoa(c.nome, c.cpfOrCNPJ);
            this->correntistas.push_back(novaPessoa);
            this->numCorrentistas ++;
        }
    }
      
    this->ler_contas();

  fin.close(); 

  return true;
}

bool Banco::ler_contas(){
    ifstream fin("contas.dat", std::ios::in);

    if (!fin){  
        return false;
    } 

    Conta_entrada c;

    while (fin >> c.num >> c.nome >> c.saldo >> c.aniver >> c.limite){  
        PessoaFisica novaFisica;
        PessoaJuridica novaJuridica;

        for(int i = 0; i < this->numCorrentistas; i++){
            if(c.nome == correntistas[i].getNome()){
                Pessoa x = correntistas[i];
                if(x.getRazao() != "x"){
                    novaJuridica.setCpfOrCNPJ(x.getCpfOrCNPJ());
                    novaJuridica.setRazao(x.getRazao());
                    novaJuridica.setNome(x.getNome());
                }else{
                    novaFisica.setCpfOrCNPJ(x.getCpfOrCNPJ());
                    novaFisica.setRazao(x.getRazao());
                    novaFisica.setNome(x.getNome());
                }
            }
        }

        if(novaFisica.getCpfOrCNPJ()){
            if (c.aniver != 0){
            ContaPoupanca novaConta(c.num, novaFisica, c.saldo, c.aniver);
            this->cadastrarConta(novaConta);
            }else if(c.limite != 0){
                ContaLimite novaConta(c.num, novaFisica, c.saldo, c.limite);
                this->cadastrarConta(novaConta);
            }else{
                ContaComum novaConta(c.num, novaFisica, c.saldo);
                this->cadastrarConta(novaConta);
            }
        }else{
            if (c.aniver != 0){
            ContaPoupanca novaConta(c.num, novaJuridica, c.saldo, c.aniver);
            this->cadastrarConta(novaConta);
            }else if(c.limite != 0){
                ContaLimite novaConta(c.num, novaJuridica, c.saldo, c.limite);
                this->cadastrarConta(novaConta);
            }else{
                ContaComum novaConta(c.num, novaJuridica, c.saldo);
                this->cadastrarConta(novaConta);
            }
        }
    }

    fin.close(); 
    return true;

}


Banco::~Banco(){
    salvar_dados();
}