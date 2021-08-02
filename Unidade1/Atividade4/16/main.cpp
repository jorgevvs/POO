#include "Carro.h"
#include <iostream>

int main(void){
    Carro meuCarro("Renault", 2020);

    Carro carro2("Chevrolet", 1999);

    meuCarro.displayMessage();

    carro2.setAno(2000);
    carro2.setMarca("Peugeot");

    carro2.displayMessage();

    std::cout << carro2.getAno() << std::endl;

    return 0;
} // g++ -Wall -std=c++17 main.cpp Carro.cpp -o main && ./main