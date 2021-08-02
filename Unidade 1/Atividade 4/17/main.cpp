#include "Banco.h"
#include <iostream>

int main(void){

    ContaBanco meuBanco(200);
    ContaBanco meuBanco2(-100);


    std::cout << "\n--- Saldos da conta 1 e 2 ---" << std::endl;
    std::cout << "Saldo da conta 1: R$" << meuBanco.getSaldo() << std::endl;
    std::cout << "Saldo da conta 2: R$" << meuBanco2.getSaldo() << std::endl;
    std::cout << "----------------------------- \n" << std::endl;


    std::cout << "Creditando na conta 2..." << std::endl;
    meuBanco2.Creditar(50.99);

    std::cout << "Debitando 201 da conta 1..." << std::endl;
    meuBanco.Debitar(201);

    std::cout << "Debitando 99.99 da conta 1..." << std::endl;
    meuBanco.Debitar(99.99);


    std::cout << "\n--- Saldos da conta 1 e 2 ---" << std::endl;
    std::cout << "Saldo da conta 1: R$" << meuBanco.getSaldo() << std::endl;
    std::cout << "Saldo da conta 2: R$" << meuBanco2.getSaldo() << std::endl;
    std::cout << "----------------------------- \n" << std::endl;

    return 0;
} // g++ -Wall -std=c++17 main.cpp Banco.cpp -o main && ./main