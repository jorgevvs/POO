#include "ContaLimite.h"

#include "Transacao.h"
#include "Banco.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include "ExcedeLimiteError.h"

ContaLimite::ContaLimite(long int numero, Pessoa &correntista, double saldo, double limite) : Conta(numero, correntista, saldo){
  this->limite = limite;
}

void ContaLimite::operator<<(double valor){
  this->saldo += valor;
  Transacao x("15/10/2021", valor, "Crédito");
  this->transacoes.push_back(x);
  cont++;
}

void ContaLimite::operator>>(double valor){
  try{
    if(this->saldo + this->limite > valor){
      this->saldo -= valor;
      Transacao x("15/10/2021", valor, "Débito");
      this->transacoes.push_back(x);
      cont++;
    }else{
      throw ExcedeLimite();
    }
  }
  catch(ExcedeLimite &e){
    cerr << e.what() << endl;
  }
}


void ContaLimite::extrato() const{
  cout << "\n\n==== Conta Corrente com Limite ====\n";
  cout << "Nome do Correntista: " << this->correntista->getNome() << endl;
  cout << "Número da conta: " << this->numero << endl;
  cout << "Saldo: $" << this->saldo << endl;
  cout << "Limite: $" << this->limite << endl;
  cout << "============Transações============\n";
  
  for (int i = 0; i < this->cont; i++){
    if(i == 30){
      break;
    }
    cout << "Data da transação: " << this->transacoes[i].getData() << endl;
    cout << "Valor da transação: $" << this->transacoes[i].getValor() << endl;
    cout << "Descrição: " << this->transacoes[i].getDescricao() << endl;
    cout << "===================================\n";
  }
}

void ContaLimite::transferir(float valor, Conta & conta){
  Transacao x("15/10/2021", valor, "Transferência");
  this->transacoes.push_back(x);
  cont ++;
  
  conta << valor;
  saldo -= valor;
}
