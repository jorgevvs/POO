#ifndef AGENDA_H
#define AGENDA_H

#include "Pessoa.h"

#include <string>

using std::string;

class Agenda{
public:
    Agenda(int);
    ~Agenda();

    void adicionaContato(Pessoa*);
    void buscaContato(string);
    void removeContato(string);

    void printAgenda() const;

private:
    int tamanhoAgenda;
    int quantidadeContatos = 0;
    Pessoa **agenda;
    int pos;
};

#endif