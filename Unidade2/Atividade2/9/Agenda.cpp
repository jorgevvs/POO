#include "Agenda.h"

#include "Pessoa.h"

#include <iostream>

Agenda::Agenda(){
    qtdePessoas = 0;
}

void Agenda::armazenaPessoa(string nome, int idade, float altura){
    if(qtdePessoas < 10){
        Pessoa nova(nome,idade,altura);
        armazenaPessoa(nova);
    }else{
        std::cout << "A agenda está cheia!" << std::endl;
    }
    
}

void Agenda::armazenaPessoa(const Pessoa &p){
    if(qtdePessoas < 10){
        pessoas[qtdePessoas] = p;
        qtdePessoas ++;
    }else{
        std::cout << "A agenda está cheia!" << std::endl;
    }
}

void Agenda::removePessoa(string nome){
    for(int i = 0; i < qtdePessoas; i++){
        if(pessoas[i].getNome() == nome){
            for(int j = i; j < qtdePessoas; j++){
                pessoas[i] = pessoas[i+1];
            }
        }
    }
    qtdePessoas --;
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
