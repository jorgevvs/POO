#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

#include "Conta.h"
#include "Transacao.h"

#include <iostream>
using std::cout;
using std::endl;

class ContaPoupanca : public Conta
{
public:
  ContaPoupanca(long int, Pessoa &, double, int);

  virtual void extrato() const;

  virtual void operator<<(double valor);
  virtual void operator>>(double valor);

  virtual void transferir(float, Conta &);
};

#endif