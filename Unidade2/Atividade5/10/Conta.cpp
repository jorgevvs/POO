#include "Conta.h"

#include <iostream>
using std::cout;
using std::endl;

Conta::Conta(long int num, string nome, double saldo){
  this->numero = num;
  this->nome = nome;
  this->saldo = saldo;
}