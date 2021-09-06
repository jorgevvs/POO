#ifndef PESSOAJURIDICA_H
#define PESSOAJURIDICA_H

#include "Pessoa.h"

#include <string>
using std::string;

class PessoaJuridica:public Pessoa{
public:
    PessoaJuridica(string, string, string, string, int, string);

    int getInscricaoEstadual() const { return this->inscricaoEstadual; }
    string getRazaoSocial() const { return this->razaoSocial; }

    virtual string getCpforCNPJ() const { return this->cnpj; }
    virtual void exibirPessoa() const;


private:
    string cnpj;
    int inscricaoEstadual;
    string razaoSocial;
};

#endif