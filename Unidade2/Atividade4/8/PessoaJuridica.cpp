#include "PessoaJuridica.h"

#include <string>
using std::string;

PessoaJuridica::PessoaJuridica(){
    this -> cnpj = 0;
    this->razao = "";
    this-> nome = "";
}

PessoaJuridica::PessoaJuridica(string name, long int num, string raz) : Pessoa(name), cnpj(num), razao(raz){
    this -> nome = name;
    this -> cnpj = num;
    this -> razao = raz;
}



long int PessoaJuridica::getCNPJ() const{
    return this ->cnpj;
}

void PessoaJuridica::setCNPJ(long int num){
    this -> cnpj = num;
}

string PessoaJuridica::getRazao() const{
    return this-> razao;
}

void PessoaJuridica::setRazao(string nome){
    this -> razao = nome;
}