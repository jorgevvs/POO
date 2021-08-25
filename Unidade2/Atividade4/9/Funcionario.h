#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "PessoaFisica.h"

#include <string>
using std::string;

class Funcionario : public PessoaFisica{
    friend ostream& operator<<(ostream&, const Funcionario);
public:
    Funcionario();
    Funcionario(string, long int, int , double, int , int);

    float calculaSalarioBruto();

    int getMatricula() const;
    void setMatricula(int);

    double getSalario() const;
    void setSalario(double);

    int getCargaHoraria() const;
    void setCargaHoraria(int);

    int getHorasTrab() const;
    void setHorasTrab(int);


private:
    int matricula;
    double salario;
    int cargaHoraria, horasTrab;
};

#endif