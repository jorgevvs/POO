#include "PessoaFisica.h"

#include <string>
using std::string;

PessoaFisica::PessoaFisica(){
    this->nome = "";
    this ->cpfOrCNPJ = 0;
}

PessoaFisica::PessoaFisica(string name, long int num) : Pessoa(name){
    this -> nome = name;
    this ->cpfOrCNPJ = num;
}