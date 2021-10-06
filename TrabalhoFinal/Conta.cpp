#include "Conta.h"

#include <iostream>
using std::cout;
using std::endl;

#include "Pessoa.h"

Conta::Conta(long int num, Pessoa &correntista, double saldo){
  this->numero = num;
  this->correntista = &correntista;
  this->saldo = saldo;
}