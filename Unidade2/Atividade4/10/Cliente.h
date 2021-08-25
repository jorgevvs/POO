#ifndef CLIENTE_H
#define CLIENTE_H

#include "PessoaFisica.h"

#include <string>
using std::string;

class Cliente : public PessoaFisica{
    friend ostream& operator<<(ostream&, const Cliente);
public:
    Cliente();
    Cliente(string, long int, long int, string);

    long int getTelefone() const;
    void setTelefone(long int);

    string getEndereco() const;
    void setEndereco(string);

private:
    long int telefone;
    string endereco;
};

#endif