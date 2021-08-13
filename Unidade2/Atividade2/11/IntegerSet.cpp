#include "IntegerSet.h"

#include <iostream>


IntegerSet unionOfSets(IntegerSet x, IntegerSet y){
    IntegerSet z;

    for(int i = 0; i < 100; i++){
        if(x.array[i] == 1 || y.array[i] == 1){
            z.array[i] = 1;
        }
    }
    return z;
}

IntegerSet intersetionOfSets(IntegerSet x, IntegerSet y){
    IntegerSet z;

    for(int i = 0; i < 100; i++){
        if(x.array[i] == 1 && y.array[i] == 1){
            z.array[i] = 1;
        }
    }
    return z;
}



IntegerSet::IntegerSet(){
    for(int i = 0; i < 100; i++){
        array[i] = 0;
    }
}

IntegerSet::IntegerSet(int x[], int tamanho){
    for(int i = 0; i < 100; i++){
        array[i] = 0;
    }
    for(int i = 0; i < tamanho; i++){
        array[x[i]] = 1;
    }
}


void IntegerSet::insertElement(int x){
    if(x < 100 && x > -1) array[x] = 1;
}

void IntegerSet::deleteElement(int x){
    if(x < 100 && x > -1) array[x] = 0;
}

void IntegerSet::print() const{
    for(int i = 0; i < 100; i++){
        if(array[i] == 1){
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}