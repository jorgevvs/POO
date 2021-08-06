#include <iostream>
#include "Retangulo.h"
int main(void){


    Retangulo ret;

    ret.setAltura(15.5);
    ret.setLargura(10);


    std::cout <<"O perímetro do retângulo é: " << ret.perimetro() << " m" <<  std::endl;
    std::cout <<"A área do retângulo é: " << ret.area() <<" m² " <<  std::endl;


    return 0;
} // g++ -Wall -std=c++17 main.cpp Retangulo.cpp -o main && ./main