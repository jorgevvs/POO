#include "ContaLimite.h"

#include "Transacao.h"

#include <iostream>
using std::cout;
using std::endl;

ContaLimite::ContaLimite(long int numero, string nome, double saldo, double limite) : Conta(numero, nome, saldo), limite(limite) {}

void ContaLimite::deposito(double valor){
  this->saldo += valor;
  Transacao x("08/09/2021", valor, "Crédito");
  this->transacoes[this->cont] = x;
  cont++;
}

void ContaLimite::retirada(double valor){
  if (saldo + limite >= valor) this->saldo -= valor;
  else{
    cout << "Limite atingido!" << endl;
    return;
  }
  Transacao x("08/09/2021", valor, "Débito");
  this->transacoes[this->cont] = x;
  cont++;
}

void ContaLimite::extrato() const{
  cout << "\n\n==== Conta Corrente com Limite ====\n";
  cout << "Nome do Correntista: " << this->nome << endl;
  cout << "Número da conta: " << this->numero << endl;
  cout << "Saldo: $" << this->saldo << endl;
  cout << "Limite: $" << this->limite << endl;
  cout << "============Transações============\n";
  
  for (int i = 0; i < this->cont; i++){
    cout << "Data da transação: " << this->transacoes[i].getData() << endl;
    cout << "Valor da transação: $" << this->transacoes[i].getValor() << endl;
    cout << "Descrição: " << this->transacoes[i].getDescricao() << endl;
    cout << "===================================\n";
  }
}