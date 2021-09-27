#include <iostream>
#include "Fila.h"
using std::cout;
using std::endl;

#include <string>
using std::string;

int main(){
    cout << "Criando fila de int" << endl;
    Fila<int, 9> *filaInt = new Fila<int, 9>;

    for(int i = 1; i <= 9; i++)
        filaInt->push(i);
    cout << endl;

    filaInt->print();

    filaInt->pop();
    filaInt->pop();
    filaInt->pop();

    cout << endl;

    filaInt->print();


    cout << "Criando fila de Strings" << endl;
    Fila<string, 5> *filaString = new Fila<string, 5>;

    filaString->push("Felipe");
    filaString->push("Matheus");
    filaString->push("Perseu");
    filaString->push("Jasão");
    filaString->push("Perséfone");
    filaString->push("Heracles");

    cout << endl;

    filaString->print();

    filaString->pop();
    filaString->pop();
    filaString->pop();
    filaString->pop();
    filaString->pop();
    filaString->pop();

    cout << endl;

    filaString->print();


    return 0;
}
