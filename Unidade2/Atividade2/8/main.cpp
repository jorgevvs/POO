#include "Pessoa.h"
#include <iostream>

int main(void){


    Pessoa a("Micael", 18, 1.93);

    Pessoa b("T", 0, 6);


    a.imprimePessoa();

    std::cout << "==============" << std::endl;
    
    b.imprimePessoa();

    std::cout << "==============" << std::endl;

    std::cout << "Modificando pessoa B..." << std::endl;

    std::cout << "==============" << std::endl;


    b.setAltura(1.76);
    b.setIdade(20);
    b.setNome("Thales");


    b.imprimePessoa();

    return 0 ;
} // g++ -Wall -std=c++17 main.cpp Pessoa.cpp -o main && ./main