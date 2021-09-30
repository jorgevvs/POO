#ifndef PESSOAJURIDICA_H
#define PESSOAJURIDICA_H

#include "Pessoa.h"

#include <string>
using std::string;

class PessoaJuridica : public Pessoa{
public:
    PessoaJuridica();
    PessoaJuridica(string,long int,string);

    void setCNPJ(long int);
    virtual long int getCNPJ() const { return this-> cnpj; };

    void setRazao(string);
    virtual string getRazao() const { return this-> razao; };

protected:
    long int cnpj;
    string razao;
};

#endif