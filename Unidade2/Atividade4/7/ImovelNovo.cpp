#include "ImovelNovo.h"

#include <string>
using std::string;



ImovelNovo::ImovelNovo(string end, double preco, double adc) : Imovel(end, preco), adicional(adc){
    this->adicional = adc;
}

double ImovelNovo::getAdicional() const{
    return this->adicional;
}

void ImovelNovo::setAdicional(double adc){
    this -> adicional = adc;
}

double ImovelNovo::getPreco() const{
    return this->preco + this->adicional;
}