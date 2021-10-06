#ifndef CONTA_H
#define CONTA_H

#include <string>
using std::string;

#include "Transacao.h"
#include "Pessoa.h"

#include <iostream>
using std::ostream;

#include <list>
using std::list;

#include <vector>
using std::vector;

class Conta{

public:
  Conta();
  Conta(long int ,Pessoa& ,double);

  virtual void operator<<(double) {};
  virtual void operator>>(double){};

  virtual void extrato() {};

  virtual long int getNumero(){ return this->numero ;};
  virtual double getSaldo(){ return this->saldo ;};
  virtual Pessoa getCorrentista(){ return *this->correntista ;};
 
  virtual void transferir(float, Conta &) { };

protected:
  Pessoa *correntista;
  double saldo;
  long int numero;
  vector<Transacao> transacoes;
  int cont = 0;
};

#endif