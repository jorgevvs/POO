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
    long int getCNPJ() const;

    void setRazao(string);
    string getRazao() const;

private:
    long int cnpj;
    string razao;
};

#endif