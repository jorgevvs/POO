#include "Transacao.h"

#include <iostream>
using std::cout;
using std::endl;

Transacao::Transacao(){}

Transacao::Transacao(string data, double valor, string descricao)
{
  this->data = data;
  this->valor = valor;
  this->descricao = descricao;
}