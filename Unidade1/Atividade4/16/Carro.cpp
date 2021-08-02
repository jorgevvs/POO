#include <iostream>
using std::cout;
using std::endl;

#include "Carro.h"

Carro::Carro(string nome, int ano){
    marca = nome;
    anoCarro = ano;
}

void Carro::setMarca(string nome){
    marca = nome;
}

void Carro::setAno(int ano){
    anoCarro = ano;
}

int Carro::getAno(){
    return anoCarro;
}

string Carro::getMarca(){
    return marca;
}

void Carro::displayMessage(){
    std::cout << "Olá, eu sou um carro da marca " << getMarca() << " do ano " << getAno() << endl;
}