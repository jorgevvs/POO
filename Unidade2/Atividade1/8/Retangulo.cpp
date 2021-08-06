#include "Retangulo.h"


Retangulo::Retangulo(){
        altura = 1.0;
        largura = 1.0;
}

void Retangulo::setAltura(float alt){
    if(alt > 20 || alt < 0) altura = 1.0;
    else altura = alt;
}

void Retangulo::setLargura(float larg){
    if(larg > 20 || larg < 0) largura = 1.0;
    else largura = larg;
}

float Retangulo::getAltura(){
    return altura;
}

float Retangulo::getLargura(){
    return largura;
}

float Retangulo::perimetro(){

    return altura*2 + largura*2;
}

float Retangulo::area(){
    return altura * largura;
}