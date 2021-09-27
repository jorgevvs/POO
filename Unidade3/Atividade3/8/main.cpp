#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "Pilha.h"

int main()
{
    //Pilha de inteiros
    Pilha<int> pi(5);
    int x = 1;

    cout << "Tentando retirar elementos de uma lista vazia!" << endl;
    pi.pop(x);
    cout << endl;
    
    cout << "Adicionando mais elementos que o tamanho da fila: " << endl;
    pi.push(x);
    pi.push(x);
    pi.push(x);
    pi.push(x);
    pi.push(x);
    pi.push(x);

    return 0;
}