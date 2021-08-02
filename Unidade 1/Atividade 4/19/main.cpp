#include "Data.h"
#include <iostream>

int main(void){
    Data novaData(10,2,2020);

    std::cout <<"\nA data de hoje é: " <<novaData.mostrarData() << std::endl;

    std::cout << "\nO dia de hoje é: " << novaData.getDia() << " do mês " << novaData.getMes() << " do ano " << novaData.getAno() << std::endl;

    std::cout << "\nModificando a data..." << std::endl;

    novaData.setAno(2021);
    novaData.setMes(15);
    novaData.setDia(5);

    std::cout <<"\nA data de hoje é: " <<novaData.mostrarData() << std::endl;

    std::cout << "\nO dia de hoje é: " << novaData.getDia() << " do mês " << novaData.getMes() << " do ano " << novaData.getAno() << std::endl;



   return 0;
} // g++ -Wall -std=c++17 main.cpp Data.cpp -o main && ./main