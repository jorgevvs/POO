#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H

#include "Pessoa.h"

#include <string>
using std::string;

class PessoaFisica : public Pessoa
{
public:
    PessoaFisica(string, string, string, string, string, string);

    string getDataDeNascimento() const { return this->dataDeNascimento; }
    string getEstadoCivil() const { return this->estadoCivil; }

    virtual string getCpforCNPJ() const { return this->cpf; }
    virtual void exibirPessoa() const;

protected:
    string cpf;
    string dataDeNascimento;
    string estadoCivil;
};

#endif