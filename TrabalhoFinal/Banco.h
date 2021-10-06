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


    void cadastrarConta(Pessoa &, string,long int, double, int);
    void removerConta(long int);
    void consultarConta(long int);
    void atualizarConta(long int, Pessoa &, string, double, int);
    
    vector<Conta> listarContasCorrentista(Pessoa& );
    vector<Conta> listarContas();

    int getNum() { return this->numContas;};


private:
    list<Pessoa> correntistas;
    vector<Conta> contas;
    int numContas = 0;

};
#endif