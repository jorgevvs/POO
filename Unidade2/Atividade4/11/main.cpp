#include "Empresa.h"

#include <iostream>
using std::cout;
using std::endl;

int main(){
    Cliente c1("Taran Matharu", 15273453622, 8394002892,"Rua Pedro Vasconcelos, 1623");
    Cliente c2("Percy Jackson" , 62362373462, 83989963253, "Rua Silvino Olavo, 453");
    Cliente c3("Ayrton Senna" , 7523162321, 83973456124, "Rua do Boi, 833");
   
    Funcionario f1("Herbert Richers", 12345678900, 15235, 2000, 30, 25);
    Funcionario f2("Indiana Jones", 52362434760, 130, 5300, 60, 80);
    Funcionario f3("Harry Potter", 84531234623, 6723, 10300, 40, 40);

    Empresa empresa("Produtos de Paris", 256123000152, "Empresa de alimentos e Bebidas");

    empresa.adicionaCliente(c1);
    empresa.adicionaCliente(c2);
    empresa.adicionaCliente(c3);

    empresa.adicionaFuncionario(f1);
    empresa.adicionaFuncionario(f2);
    empresa.adicionaFuncionario(f3);

    empresa.imprimeClientes();

    empresa.imprimeFuncionarios();

    cout <<  "\nTotal gasto com funcionários: R$" <<empresa.calcularFolhaDePagamento() << endl;
    
    return 0;
} // g++ -Wall -std=c++17 main.cpp Pessoa.cpp PessoaFisica.cpp Cliente.cpp Funcionario.cpp PessoaJuridica.cpp Empresa.cpp -o main && ./main