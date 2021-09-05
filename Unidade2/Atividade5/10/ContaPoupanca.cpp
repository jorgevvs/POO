#include "ContaPoupanca.h"

#include "Transacao.h"

#include <iostream>
using std::cout;
using std::endl;

ContaPoupanca::ContaPoupanca(long int numero, string nome, double saldo, int aniversarioConta) : Conta(numero, nome, saldo), aniversarioConta(aniversarioConta) {}

void ContaPoupanca::deposito(double valor){
  this->saldo += valor;
  Transacao x("07/09/2021", valor,"Crédito" );
  this->transacoes[this->cont] = x;
  cont++;
}

void ContaPoupanca::retirada(double valor){
  this->saldo -= valor;
  Transacao x("07/09/2021", valor, "Débito");
  this->transacoes[this->cont] = x;
  cont++;
}

void ContaPoupanca::extrato() const{
  cout << "\n\n======== Conta Poupança ========\n";
  cout << "Nome do Correntista: " << this->nome << endl;
  cout << "Número da conta: " << this->numero << endl;
  cout << "Saldo: $" << this->saldo << endl;
  cout << "Aniversario da Conta: " << this->aniversarioConta << endl;
  cout << "===========Transações===========\n";

  for (int i = 0; i < this->cont; i++){
    cout << "Data da transação: " << this->transacoes[i].getData() << endl;
    cout << "Valor da transação: $" << this->transacoes[i].getValor() << endl;
    cout << "Descrição: " << this->transacoes[i].getDescricao() << endl;
    cout << "================================\n";
  }
}