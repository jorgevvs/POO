#include <iostream>

#include <string>
#include "Cupom.h"

Cupom::Cupom(string id, string description, int quant, float preco){
    cupomId = id;
    cupomDesc = description;
    if (quant > 0) cupomQuant = quant;
    else cupomQuant = 0;

    if (preco > 0) cupomPreco = preco;
    else cupomPreco = 0;
}

void Cupom::setId(string id){
    cupomId = id;
}

void Cupom::setDesc(string desc){
    cupomDesc = desc;
}
void Cupom::setQuant(int quant){
    if (quant > 0) cupomQuant = quant;
    else cupomQuant = 0;
}
void Cupom::setPreco(float preco){
    if (preco > 0) cupomPreco = preco;
    else cupomPreco = 0;
}

string Cupom::getId(){
    return cupomId;
}

string Cupom::getDesc(){
    return cupomDesc;
}

int Cupom::getQuant(){
    return cupomQuant;
}

float Cupom::getPreco(){
    return cupomPreco;
}

float Cupom::calculaCupom(){
    float valor = cupomPreco * cupomQuant;
    return valor;
}