#include "Imovel.h"


Imovel::Imovel(){
    this -> endereco = "";
    this ->preco = 0;
}

Imovel::Imovel(string end, double preco){
    this -> endereco = end;
    this -> preco = preco;
}

string Imovel::getEndereco() const{
    return this->endereco;
}

double Imovel::getPreco() const{
    return this -> preco;
}

void Imovel::setEndereco(string end){
    this->endereco = end;
}

void Imovel::setPreco(double preco){
    this ->preco = preco;
}