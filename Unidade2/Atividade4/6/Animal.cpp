#include "Animal.h"

Animal::Animal(){
    this->nome = "";
    this->raca = "";
}

Animal::Animal(string nome, string raca){
    this-> nome = nome;
    this-> raca = raca;
}

string Animal::caminha()const {
    return this->nome + " " + this->raca + " está caminhando...";
}