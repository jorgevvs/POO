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
    ~Banco();

    void cadastrarConta(Conta& conta);
    void removerConta(long int);
    void consultarConta(long int);
    void atualizarConta(Conta&, int);

    void cadastrarCorrentista(Pessoa &);
    
    void listarContasCorrentista(Pessoa& );
    void listarContas();

    Pessoa& achaCorrentista(string);
    Conta& achaConta(long int);

    int getNum() { return this->numContas;};

    bool salvar_dados();
    bool salva_pessoas();
    bool ler_dados();
    bool ler_contas();

private:
    vector<Pessoa> correntistas;
    vector<Conta> contas;
    int numContas = 0;
    int numCorrentistas = 0;

};
#endif