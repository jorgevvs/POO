#ifndef CONTA_H
#define CONTA_H

#include <string>
#include "Transacao.h"

using std::string;

class Conta{
public:
  Conta(long int ,string ,double);

  virtual void deposito(double=0) = 0;
  virtual void retirada(double=0) = 0;
  virtual void extrato() const = 0;

protected:
  string nome;
  double saldo;
  long int numero;
  Transacao transacoes[100];
  int cont = 0;
};

#endif