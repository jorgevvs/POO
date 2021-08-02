#include "Empregado.h"
#include <iostream>

int main(void){

    Empregado empregado1("Micael","Rafles",1000.00);

    Empregado empregado2("Angelo","Praxedes",-500.00);

    std::cout << "\n----- Salarios mensais dos empregados 1 e 2 -----" << std::endl;
    std::cout << "O empregado " << empregado1.getNome() << " " << empregado1.getSobrenome() << " tem um salário de " << empregado1.getSal() << std::endl;
    std::cout << "O empregado " << empregado2.getNome() << " " << empregado2.getSobrenome() << " tem um salário de " << empregado2.getSal() << std::endl;
    std::cout << "------------------------------------------------- \n" << std::endl;

    std::cout << "Modificando o salário do empregado 2..." <<  std::endl;

    empregado2.setSal(2200.50);

    std::cout << "Dando um aumento de 10% nos salários..." <<  std::endl;

    empregado1.setSal( empregado1.getSal() + empregado1.getSal()*0.1);
    empregado2.setSal( empregado2.getSal() + empregado2.getSal()*0.1);

    std::cout << "\n----- Salarios mensais dos empregados 1 e 2 -----" << std::endl;
    std::cout << "O empregado " << empregado1.getNome() << " " << empregado1.getSobrenome() << " tem um salário de R$" << empregado1.getSal() << std::endl;
    std::cout << "O empregado " << empregado2.getNome() << " " << empregado2.getSobrenome() << " tem um salário de R$" << empregado2.getSal() << std::endl;
    std::cout << "------------------------------------------------- \n" << std::endl;

   
   return 0;
} // g++ -Wall -std=c++17 main.cpp Empregado.cpp -o main && ./main