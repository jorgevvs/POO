#include "ExcecaoDerivada.h"

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <stdexcept>
using std::runtime_error;

void ChamadaExcecao(){
    throw ExcecaoDerivada();
}

int main(){

    try{
        ChamadaExcecao();
    }catch(runtime_error &e){
        cout << "Capturando runtime_error de classe derivada!" << endl;
        cerr << e.what() << endl;
    }

    

    return 0;
}