#include <iostream>
using std::cout;
using std::endl;

#include "Pessoa.h"
#include "PessoaJuridica.h"
#include "PessoaFisica.h"

int main (){
    Pessoa p1("Jorge Castro");
    PessoaJuridica p2("Leonardo da Vinci", 12345678000123 , "Davinci");
    PessoaFisica p3;
    p3.setCPF(12345678900);
    p3.setNome("Alexandre Bessa");

    cout << p1;
    cout << p2 << p2.getCNPJ() << endl;
    cout << p3 << p3.getCPF() << endl;


    return 0;
} // g++ -Wall -std=c++17 main.cpp Pessoa.cpp PessoaJuridica.cpp PessoaFisica.cpp -o main && ./main