#ifndef CONTACORRENTECOMUM_H
#define CONTACORRENTECOMUM_H

#include "Conta.h"
#include "Transacao.h"

#include <iostream>
using std::cout;
using std::endl;

class ContaComum : public Conta
{
public:
  ContaComum(long int, Pessoa &, double);

  virtual void operator<<(double valor);
  virtual void operator>>(double valor);

  virtual void extrato() const;

  virtual void transferir(float, Conta &);

  virtual double getLimite() { return 0; };
  virtual int getAniver() { return 0; };

};

#endif