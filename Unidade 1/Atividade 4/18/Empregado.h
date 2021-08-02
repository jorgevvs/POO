#ifndef EMPREGADO_H
#define EMPREGADO_H

#include <string>
using std::string;

class Empregado
{
public:
    Empregado(string nome, string sobrenome, double salario);

    void setNome(string nome);

    void setSobrenome(string nome);

    void setSal(double salario);

    string getNome();

    string getSobrenome();

    double getSal();

private:
    double salMensal;
    string nomeEmpregado;
    string sobrenomeEmpregado;
};

#endif