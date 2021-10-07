#include "Banco.h"
#include "ContaComum.h"
#include "ContaLimite.h"
#include "ContaPoupanca.h"
#include "PessoaFisica.h"
#include "PessoaJuridica.h"
#include "Conta.h"


#include <iomanip>
using std::setw;

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios;

#include <iostream>
using std::cout;
using std::cin;
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
    numContas --;
}

void Banco::consultarConta(long int num){
    for(int i = 0; i < numContas; i++){
        if(this->contas[i].getNumero() == num){
            cout << "\n\n\n\n========== Consulta ==========\n";
            cout << "Nome do Correntista: " << contas[i].getCorrentista().getNome() << endl;
            cout << "Número da conta: " << contas[i].getNumero() << endl;
            cout << "Saldo: $" << contas[i].getSaldo() << endl;
            cout << "==============================\n\n\n" << endl;
        }
    }
}

void Banco::atualizarConta(Conta& conta, int tipoConta){
    if(tipoConta == 2){
        double limite;
        cout << "Digite um limite inicial: ";
        cin >> limite;

        if(conta.getCorrentista().getRazao() != "x"){
            ContaLimite novaConta(conta.getNumero(), this->achaCorrentista(conta.getCorrentista().getNome()), conta.getSaldo(), limite);

            this->removerConta(conta.getNumero());
            this->cadastrarConta(novaConta);
        }else{
            ContaLimite novaConta(conta.getNumero(), this->achaCorrentista(conta.getCorrentista().getNome()), conta.getSaldo(), limite);

            this->removerConta(conta.getNumero());
            this->cadastrarConta(novaConta);
        }

    }else if(tipoConta == 3){
        int aniver;
        cout << "Digite uma data para o Aniversário da conta: ";
        cin >> aniver;
        
        if(conta.getCorrentista().getRazao() != "x"){
            ContaPoupanca novaConta(conta.getNumero(), this->achaCorrentista(conta.getCorrentista().getNome()), conta.getSaldo(), aniver);
            this->removerConta(conta.getNumero());
            this->cadastrarConta(novaConta);
        }else{
            ContaPoupanca novaConta(conta.getNumero(), this->achaCorrentista(conta.getCorrentista().getNome()), conta.getSaldo(), aniver);
            this->removerConta(conta.getNumero());
            this->cadastrarConta(novaConta);
        }
    }else{
        if(conta.getCorrentista().getRazao() != "x"){
            ContaComum novaConta(conta.getNumero(), this->achaCorrentista(conta.getCorrentista().getNome()), conta.getSaldo());
            this->removerConta(conta.getNumero());
            this->cadastrarConta(novaConta);
        }else{
            ContaComum novaConta(conta.getNumero(), this->achaCorrentista(conta.getCorrentista().getNome()), conta.getSaldo());
            this->removerConta(conta.getNumero());
            this->cadastrarConta(novaConta);
        }
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

void Banco::cadastrarCorrentista(Pessoa& correntista){
    this->correntistas.push_back(correntista);
    this->numCorrentistas++;
}

Pessoa& Banco::achaCorrentista(string nome){
    for(int i = 0; i < numCorrentistas; i ++){
        if(correntistas[i].getNome() == nome){
            return correntistas[i];
        }
    }

    return this->correntistas[0];
}

Conta& Banco::achaConta(long int num){
    for(int i = 0; i < numContas; i ++){
        if(contas[i].getNumero() == num){
            return contas[i];
        }
    }
    return this->contas[0];
}

bool Banco::ler_contas(){
    ifstream fin("contas.dat", std::ios::in);

    if (!fin){  
        return false;
    } 
    Conta_entrada c;

    while (fin >> c.num >> c.nome >> c.saldo >> c.aniver >> c.limite){  
        
        if (c.aniver != 0){
            ContaPoupanca novaConta(c.num, this->achaCorrentista(c.nome), c.saldo, c.aniver);
            this->cadastrarConta(novaConta);

        }else if(c.limite != 0){
            ContaLimite novaConta(c.num, this->achaCorrentista(c.nome), c.saldo, c.limite);
            this->cadastrarConta(novaConta);

        }else{
            ContaComum novaConta(c.num, this->achaCorrentista(c.nome), c.saldo);
            this->cadastrarConta(novaConta);
        }
    }
    fin.close(); 
    return true;

}


Banco::~Banco(){
    salvar_dados();
}