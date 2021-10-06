#include "PessoaJuridica.h"

#include <string>
using std::string;

PessoaJuridica::PessoaJuridica(){
    this -> cpfOrCNPJ = 0;
    this->razao = "";
    this-> nome = "";
}

PessoaJuridica::PessoaJuridica(string name, long int num, string raz) : Pessoa(name){
    this -> nome = name;
    this -> cpfOrCNPJ = num;
    this -> razao = raz;
}


void PessoaJuridica::setCNPJ(long int num){
    this ->cpfOrCNPJ = num;
}

void PessoaJuridica::setRazao(string nome){
    this -> razao = nome;
}