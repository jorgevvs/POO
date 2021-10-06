#ifndef BANCO_H
#define BANCO_H

#include "PessoaJuridica.h"
#include "Pessoa.h"
#include "Conta.h"

#include <list>
using std::list;

#include <string>
using std::string;

#include <vector>
using std::vector;

class Banco: public PessoaJuridica{
public:
    Banco(string, long int, string);


    void cadastrarConta(Conta& conta);
    void removerConta(long int);
    void consultarConta(long int);
    void atualizarConta(long int, Pessoa &, string, double, int);
    
    void listarContasCorrentista(Pessoa& );
    void listarContas();

    int getNum() { return this->numContas;};


private:
    list<Pessoa> correntistas;
    vector<Conta> contas;
    int numContas = 0;

};
#endif