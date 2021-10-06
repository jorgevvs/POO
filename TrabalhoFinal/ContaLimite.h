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
  ContaLimite(long int, Pessoa & ,double, double);

  virtual void extrato() const;

  virtual void operator<<(double valor);
  virtual void operator>>(double valor);

  virtual void transferir(float, Conta &);

};

#endif