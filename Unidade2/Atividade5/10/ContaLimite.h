#ifndef QUADRADO_H
#define QUADRADO_H

#include "Conta.h"
#include "Transacao.h"

#include <iostream>
using std::cout;
using std::endl;

class ContaLimite : public Conta
{
public:
  ContaLimite(long int ,string ,double, double);

  virtual void deposito(double valor);

  virtual void retirada(double valor);

  virtual void extrato() const;

private:
  double limite;
};

#endif