#include "IntegerSet.h"

#include <iostream>

int main(void){

    int lista[9] = {1,2,3,5,23,33,55,99};
    int lista2[6] = {1,2,3,55,88,99};
    int lista3[6] = {4,5,6,7,8,9};

    std::cout << "Criando arrays..." << std::endl;

    IntegerSet x(lista, 8);
    IntegerSet y(lista2, 6);
    IntegerSet z(lista3, 6);

    std::cout << "Array X: " ;
    x.print();

    std::cout << "Array Y: " ;
    y.print();

    std::cout << "Array Z: " ;
    z.print();

    std::cout << "\nInserindo os numeros 100 e 98, e removendo 2 no array X..." << std::endl;
    x.insertElement(100);
    x.insertElement(98);
    x.deleteElement(2);

    std::cout << "\nNovo array X: ";

    x.print();

    std::cout << "\nConjunto união do array Y e Z: ";

    unionOfSets(y,z).print();

    std::cout << "\nConjunto intersecção do array X e Y: ";

    intersetionOfSets(x,y).print();






    return 0;
} // g++ -Wall -std=c++17 main.cpp IntegerSet.cpp -o main && ./main