#include <iostream>

#include "Huge.h"

int main(void){
    HugeInteger num, num2, num3;
    num.input("999");
    num2.input("999");
    num3.input("1000");

    std::cout << "Num1: ";
    num.output();
    std::cout << "Num2: ";
    num2.output();
    std::cout << "Num3: ";
    num3.output();

    std::cout << "\nAdicionando num2 em num1...\n" << std::endl;
    num.add(num2);

    std::cout << "Num1: ";
    num.output();
    std::cout << "Num2: ";
    num2.output();
    std::cout << "Num3: ";
    num3.output();


    std::cout << "\nNum1 é maior que num2: "  << num.isGreaterThan(num2) << std::endl;
    std::cout << "Num1 é maior ou igual a num2: "<< num.isGreaterThanOrEqual(num2) << std::endl;
    std::cout << "Num1 é menor que num2: "<< num.isLessThan(num2) << std::endl;
    std::cout << "Num1 é menor ou igual a num2: "<<num.isLessThanOrEqual(num2) << std::endl;
    std::cout << "Num1 é igual a num2: "<<num.isEqualTo(num2) << std::endl;
    std::cout << "Num1 não é igual a num2: "<<num.isNotEqualTo(num2) << std::endl;
    std::cout << "Num1 é igual a num3: "<<num.isEqualTo(num3) << std::endl;
    std::cout << "Num1 é maior igual a num3: "<<num.isGreaterThanOrEqual(num3) << std::endl;


    return 0;
} // g++ -Wall -std=c++17 main.cpp Huge.cpp -o main && ./main