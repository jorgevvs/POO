#ifndef BANCO_H
#define BANCO_H



#include "PessoaJuridica.h"
#include "Pessoa.h"
#include "Conta.h"

#include <list>
using std::list;

class Banco: public PessoaJuridica{








private:
    list<Pessoa> correntistas;


};
#endif