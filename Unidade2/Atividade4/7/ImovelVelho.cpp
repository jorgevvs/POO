#include "ImovelVelho.h"

#include <string>
using std::string;

ImovelVelho::ImovelVelho(string end, double preco, double adc) : Imovel(end, preco), desconto(adc){
    this->desconto = adc;
}

double ImovelVelho::getDesconto() const{
    return this->desconto;
}

void ImovelVelho::setDesconto(double adc){
    this -> desconto = adc;
}

double ImovelVelho::getPreco() const{
    return this->preco - this->desconto;
}