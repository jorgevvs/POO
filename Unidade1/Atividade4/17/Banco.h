#ifndef BANCO_H
#define BANCO_H

#include <string>
using std::string;

class ContaBanco
{
public:

    ContaBanco(double valor);

    void Creditar(double valor);

    void Debitar(double valor);

    double getSaldo();

private:
    double saldo;
};

#endif