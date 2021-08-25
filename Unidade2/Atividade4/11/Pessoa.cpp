#include "Pessoa.h"

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

ostream& operator<<(ostream& out, Pessoa x){
  cout << x.getNome() << endl;
  return out;
}

Pessoa::Pessoa(){
    this->nome = "";
}

Pessoa::Pessoa(string name){
    this->nome = name;
}

string Pessoa::getNome() const{
    return this ->nome;
}

void Pessoa::setNome(string name){
    this ->nome = name;
}