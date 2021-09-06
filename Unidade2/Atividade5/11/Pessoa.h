#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using std::string;

class Pessoa{
public:
    Pessoa(string nome, string endereco, string email): nome(nome),endereco(endereco), email(email){}

    virtual ~Pessoa() {}

    string getNome() const { return nome; };
    string getEndereco() const { return endereco; };
    string getEmail() const { return email; };

    virtual string getCpforCNPJ() const = 0;
    virtual void exibirPessoa() const = 0;

protected:
    string nome;
    string endereco;
    string email;
};

#endif