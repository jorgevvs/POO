#include "Agenda.h"

#include "Pessoa.h"

#include <iostream>

Agenda::Agenda(int tPessoas){
    pessoas = new Pessoa[tPessoas];
    qtdePessoas = 0;
}

Agenda::~Agenda(){
    delete[] pessoas;
}

void Agenda::armazenaPessoa(string nome, int idade, float altura){
    Pessoa nova(nome,idade,altura);
    armazenaPessoa(nova);
}

void Agenda::armazenaPessoa(const Pessoa &p){
    if(qtdePessoas < 10){
        pessoas[qtdePessoas] = p;
        qtdePessoas ++;
    }
}

void Agenda::removePessoa(string nome){
    for (int i = buscaPessoa(nome); i < qtdePessoas; i++){
        pessoas[i - 1] = pessoas[i];
  }
  qtdePessoas--;
}

int Agenda::buscaPessoa(string nome) const{
    for(int i = 0; i < qtdePessoas; i++){
        if(pessoas[i].getNome() == nome){
            return i+1;
        }
    }
    return 0;
}

void Agenda::imprimePovo() const{
    for(int i = 0; i < qtdePessoas; i++){
        std::cout << "Pessoa numero "<< i+1 << ": " << pessoas[i].getNome() << std::endl;
        std::cout << "Tem " << pessoas[i].getIdade() << " anos de idade." << std::endl; 
        std::cout << "E " << pessoas[i].getAltura() << " m de altura." << std::endl; 
        std::cout << "======================" << std::endl;
    }
}

void Agenda::imprimePessoa(int i) const{
    std::cout << "Pessoa numero "<< i << ": " << pessoas[i-1].getNome() << std::endl;
    std::cout << "Tem " << pessoas[i-1].getIdade() << " anos de idade." << std::endl; 
    std::cout << "E " << pessoas[i-1].getAltura() << " m de altura." << std::endl; 
    std::cout << "======================" << std::endl;
} 
