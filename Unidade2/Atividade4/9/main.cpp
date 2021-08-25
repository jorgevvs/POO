#include "Funcionario.h"

#include <iostream>
using std::cout;
using std::endl;


int main(){
    Funcionario f1("Herbert Richers", 12345678900, 15235, 2000, 30, 25);
    Funcionario f2;
    f2.setCargaHoraria(60);
    f2.setCPF(52362434760);
    f2.setNome("Indiana Jones");
    f2.setSalario(5300.00);
    f2.setMatricula(130);
    f2.setHorasTrab(80);

    cout << f1 << "\n" << f2;

    cout << "\nFuncionario f1 trabalhou " << f1.getHorasTrab() << " de " << f1.getCargaHoraria() << " em sua carga horaria.\n" <<endl;

    return 0;
} // g++ -Wall -std=c++17 main.cpp Pessoa.cpp PessoaFisica.cpp Funcionario.cpp -o main && ./main