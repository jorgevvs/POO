#include <iostream>

#include "Conta.h"
#include "ContaPoupanca.h"
#include "ContaLimite.h"
#include "ContaComum.h"

int main(){
  ContaPoupanca c1(523162350001,"Gabigol", 1500.00, 10);
  ContaComum c2(25231620001, "Thanatos", 500.00);
  ContaLimite c3(6341266529, "João Marcos", 3200.00, 200.00);

  c3.deposito(800);
  c3.retirada(4100);
  c3.extrato();

  c2.deposito(100);
  c2.deposito(100);
  c2.deposito(400);
  c2.retirada(200);
  c2.extrato();

  c1.deposito(500);
  c1.extrato();

  return 0;
} // g++ -Wall -std=c++17 main.cpp Conta.cpp ContaComum.cpp ContaPoupanca.cpp ContaLimite.cpp Transacao.cpp -o main && ./main