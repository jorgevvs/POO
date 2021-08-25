#include "Cliente.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

ostream& operator<<(ostream& out, Cliente x){
    cout << "===========================================\n";
    cout << "Cliente: " << x.getNome() << " \nCPF: " << x.getCPF() << " \nTelefone: " << x.getTelefone() << " \nEndereço: " << x.getEndereco() << endl;
    return out;
}

Cliente::Cliente(){
    this->nome = "";
    this->cpf = 0;
    this->endereco = "";
    this->telefone = 0;
}

Cliente::Cliente(string nome, long int cpf, long int telefone, string endereco) : PessoaFisica(nome,cpf) , telefone(telefone) , endereco(endereco){
    this->nome = nome;
    this->cpf = cpf;
    this->endereco = endereco;
    this->telefone = telefone;
}

long int Cliente::getTelefone() const{
    return this->telefone;
}

void Cliente::setTelefone(long int num){
    this->telefone = num;
}

string Cliente::getEndereco() const{
    return this->endereco;
}

void Cliente::setEndereco(string end){
    this-> endereco = end;
}