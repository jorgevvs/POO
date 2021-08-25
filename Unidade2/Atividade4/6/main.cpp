#include "Animal.h"
#include "Cachorro.h"
#include "Gato.h"

#include <iostream>
using std::cout;
using std::endl;

int main(){
    Gato miau("Garfield", "Persa");
    Cachorro auau("Caramelo", "Vira-Lata");

    cout << miau.mia() << endl;
    cout << auau.late() << endl;

    return 0;
}