#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using std::string;

class Pessoa{
public:
    Pessoa() {};
    Pessoa(string nome): nome(nome){}

    virtual string getNome() const { return this-> nome; };

    virtual long int getCpfOrCNPJ() { return this->cpfOrCNPJ;};
    virtual string getRazao() { return this->razao;};

protected:
    string nome;
    long int cpfOrCNPJ = 0;
    string razao = "x";

};

#endif