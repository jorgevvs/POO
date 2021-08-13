#include "Pessoa.h"

#include <string>
using std::string;

#include <iostream>

Pessoa::Pessoa(string name, int age, float height){
    setNome(name);
    setAltura(height);
    setIdade(age);
}

void Pessoa::setNome(string name){
    nome = name;
}

void Pessoa::setIdade(int age){
    idade = age;
}

void Pessoa::setAltura(float height){
    altura = height;
}

void Pessoa::imprimePessoa() const{
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Altura: " << altura << " m" << std::endl;
    std::cout << "Idade: " << idade << " anos" << std::endl;
}