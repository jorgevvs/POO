#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using std::string;

class Pessoa{
public:
    Pessoa() {};
    Pessoa(string nome): nome(nome){}

    virtual string getNome() const { return this-> nome; };

protected:
    string nome;

};

#endif