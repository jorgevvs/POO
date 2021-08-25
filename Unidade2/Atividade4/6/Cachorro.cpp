#include "Cachorro.h"

#include <string>
using std::string;

Cachorro::Cachorro(){
    this->nome = "";
    this->raca = "";
}

Cachorro::Cachorro(string nome, string raca): Animal(nome,raca){
    this->nome = nome;
    this-> raca = raca;
}

string Cachorro::late()const {
    return "O cachorro " + this ->nome + " da raça " + this ->raca + " está latindo! AUAU!!!"; 
}