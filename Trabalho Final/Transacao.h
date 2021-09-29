#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <string>

using std::string;

class Transacao
{
public:
  Transacao();
  Transacao(string, double, string);

  string getData() const { return this->data; }
  double getValor() const { return this->valor; }
  string getDescricao() const { return this->descricao; }

protected:
  string data;
  double valor;
  string descricao;
};

#endif