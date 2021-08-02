#include <iostream>

#include <string>
#include "Banco.h"

ContaBanco::ContaBanco(double valor){

        if(valor > 0) saldo = valor;
        else saldo = 0;
}

void ContaBanco::Creditar(double valor){
    saldo += valor;
}

void ContaBanco::Debitar(double valor){

    if(valor > saldo) std::cout << "\nNão há saldo para debitar essa quantia." << std::endl;
    else  saldo -= valor;

}

double ContaBanco::getSaldo(){
    return saldo;
}