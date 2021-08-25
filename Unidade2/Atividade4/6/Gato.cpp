#include "Gato.h"

Gato::Gato(){
    this -> nome = "";
    this -> raca = "";
}

Gato::Gato(string nome, string raca) : Animal(nome, raca){
    this -> nome = nome;
    this -> raca = raca;
}

string Gato::mia() const{
    return "O gato " + this ->nome + " da raça " + this ->raca + " está miando! MIAU!!!"; 
}