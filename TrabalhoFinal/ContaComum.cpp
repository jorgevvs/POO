#include "ContaComum.h"
#include "Transacao.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include "Saldo_Insuficiente_Error.h"

ContaComum::ContaComum(long int numDaConta, Pessoa & correntista, double saldo) : Conta(numDaConta, correntista, saldo) {}


void ContaComum::operator>>(double valor){
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

void ContaComum::operator<<(double valor){
  if (valor > 0) this->saldo += valor;
  Transacao x("15/10/2021", valor, "Crédito");
  this->transacoes.push_back(x);
  cont++;
}

void ContaComum::extrato() const{
  cout << "\n\n========== Conta Comum ==========\n";
  cout << "Nome do Correntista: " << this->correntista->getNome() << endl;
  cout << "Número da conta: " << this->numero << endl;
  cout << "Saldo: $" << this->saldo << endl;
  cout << "============Transações============\n";

  for (int i = 0; i < this->cont; i++){
    if(i == 30){
      break;
    }
    
    cout << "Data da transação: " << this->transacoes[i].getData() << endl;
    cout << "Valor da transação: $" << this->transacoes[i].getValor() << endl;
    cout << "Descrição: " << this->transacoes[i].getDescricao() << endl;
    cout << "=================================\n";
  }
}

void ContaComum::transferir(float valor, Conta & conta){
  Transacao x("15/10/2021", valor, "Transferência");
  this->transacoes.push_back(x);
  cont ++;
  
  conta << valor;
  saldo -= valor;
}
