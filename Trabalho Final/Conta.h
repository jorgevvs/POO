#ifndef CONTA_H
#define CONTA_H

#include <string>
#include "Transacao.h"
#include "Pessoa.h"

#include <iostream>
using std::ostream;
using std::string;

#include <list>
using std::list;


class Conta{

public:
  Conta();
  Conta(long int ,Pessoa& ,double);

  virtual void operator<<(double) {};
  virtual void operator>>(double){};

  virtual void extrato() {};
 
  // virtual void transferir(float, long int) = 0;

protected:
  Pessoa *correntista;
  double saldo;
  long int numero;
  Transacao transacoes[100];
  int cont = 0;
};

#endif