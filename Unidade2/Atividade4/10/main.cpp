#include "Cliente.h"

#include <iostream>
using std::cout;
using std::endl;


int main (){
    Cliente c1;
    Cliente c2("Percy Jackson" , 62362373462, 83989963253, "Rua Silvino Olavo, 453");

    c1.setCPF(15273453622);
    c1.setEndereco("Rua Pedro Vasconcelos, 1623");
    c1.setNome("Chico Bento");
    c1.setTelefone(83940028922);

    cout << c1 << c2;

    return 0;
} // g++ -Wall -std=c++17 main.cpp Pessoa.cpp PessoaFisica.cpp Cliente.cpp -o main && ./main