#include "PessoaFisica.h"

#include <string>
using std::string;

PessoaFisica::PessoaFisica(){
    this->nome = "";
    this ->cpf = 0;
}

PessoaFisica::PessoaFisica(string name, long int num) : Pessoa(name),cpf(num){
    this -> nome = name;
    this ->cpf = num;
}

long int PessoaFisica::getCPF() const{
    return this ->cpf;
}

void PessoaFisica::setCPF(long int num){
    this ->cpf = num;
}