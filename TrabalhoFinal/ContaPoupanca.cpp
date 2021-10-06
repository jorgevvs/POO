#include "ContaPoupanca.h"

#include "Transacao.h"
#include "Banco.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include "Saldo_Insuficiente_Error.h"

ContaPoupanca::ContaPoupanca(long int numero, Pessoa &correntista, double saldo, int aniversarioConta) : Conta(numero, correntista, saldo){
  this->aniversarioConta = aniversarioConta;
}

void ContaPoupanca::operator<<(double valor){
  this->saldo += valor;
  Transacao x("15/10/2021", valor,"Crédito" );
  this->transacoes.push_back(x);
  cont++;
}

void ContaPoupanca::operator>>(double valor){
  try{
    if(this->saldo > valor){
      this->saldo -= valor;
      Transacao x("15/10/2021", valor, "Débito");
      this->transacoes.push_back(x);
      cont++;
    }else{
      throw saldo_insuficiente_error();
    }
  }
  catch(saldo_insuficiente_error &e){
    cerr << e.what() << endl;
  }
}

void ContaPoupanca::extrato() const{
  cout << "\n\n======== Conta Poupança ========\n";
  cout << "Nome do Correntista: " << this->correntista->getNome() << endl;
  cout << "Número da conta: " << this->numero << endl;
  cout << "Saldo: $" << this->saldo << endl;
  cout << "Aniversario da Conta: " << this->aniversarioConta << endl;
  cout << "===========Transações===========\n";

  for (int i = 0; i < this->cont; i++){
    if(i == 30){
      break;
    }

    cout << "Data da transação: " << this->transacoes[i].getData() << endl;
    cout << "Valor da transação: $" << this->transacoes[i].getValor() << endl;
    cout << "Descrição: " << this->transacoes[i].getDescricao() << endl;
    cout << "================================\n";
  }
}


void ContaPoupanca::transferir(float valor, Conta & conta){
  Transacao x("15/10/2021", valor, "Transferência");
  this->transacoes.push_back(x);
  cont ++;
  
  conta << valor;
  saldo -= valor;
}