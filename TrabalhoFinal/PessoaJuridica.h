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
    void setRazao(string);

};

#endif