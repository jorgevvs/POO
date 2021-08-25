#ifndef EMPRESA_H
#define EMPRESA_H

#include "PessoaJuridica.h"
#include "Cliente.h"
#include "Funcionario.h"

#include <string>
using std::string;

class Empresa : public PessoaJuridica{
public:
    Empresa();
    Empresa(string, long int, string);

    void adicionaCliente(Cliente const);

    void adicionaFuncionario(Funcionario const);

    void imprimeClientes() const;

    void imprimeFuncionarios() const;

    double calcularFolhaDePagamento();


private:
    Cliente clientes[10];
    int quantClientes = 0;
    Funcionario funcionarios[10];
    int quantFuncionarios = 0;
};

#endif