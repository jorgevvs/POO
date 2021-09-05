#include "ContaComum.h"
#include "Transacao.h"

#include <iostream>
using std::cout;
using std::endl;

ContaComum::ContaComum(long int numDaConta, string nome, double saldo) : Conta(numDaConta, nome, saldo) {}

void ContaComum::deposito(double valor){
  if (valor > 0) this->saldo += valor;

  Transacao x("07/09/2021", valor, "Crédito");
  this->transacoes[this->cont] = x;
  cont++;
}

void ContaComum::retirada(double valor){
  this->saldo -= valor;
  Transacao x("07/09/2021", valor, "Débito");
  this->transacoes[this->cont] = x;
  cont++;
}

void ContaComum::extrato() const{
  cout << "\n\n========== Conta Comum ==========\n";
  cout << "Nome do Correntista: " << this->nome << endl;
  cout << "Número da conta: " << this->numero << endl;
  cout << "Saldo: $" << this->saldo << endl;
  cout << "============Transações============\n";

  for (int i = 0; i < this->cont; i++){
    
    cout << "Data da transação: " << this->transacoes[i].getData() << endl;
    cout << "Valor da transação: $" << this->transacoes[i].getValor() << endl;
    cout << "Descrição: " << this->transacoes[i].getDescricao() << endl;
    cout << "=================================\n";
  }
}