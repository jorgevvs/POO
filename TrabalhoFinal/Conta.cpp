#include "Conta.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include "Pessoa.h"
#include "Saldo_Insuficiente_Error.h"
#include "ExcedeLimiteError.h"

Conta::Conta(long int num, Pessoa &correntista, double saldo){
  this->numero = num;
  this->correntista = &correntista;
  this->saldo = saldo;
}

void Conta::extrato() const{
  cout << "\n\n========== Extrato ===========\n";
  cout << "Nome do Correntista: " << this->correntista->getNome() << endl;
  cout << "Número da conta: " << this->numero << endl;
  cout << "Saldo: $" << this->saldo << endl;
  cout << "========== Transações ==========\n";
  
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

void Conta::transferir(float valor, Conta & conta){
    if(this->limite > 0){
    try{
    if(this->saldo > valor){
      this->saldo -= valor;
      Transacao x("15/10/2021", valor, "Transferência");
      this->transacoes.push_back(x);
      cont ++;
      conta << valor;
      }else{
        throw ExcedeLimite();
      }
    }
    catch(ExcedeLimite &e){
      cerr << e.what() << endl;
    }
    }else{
      try{
        if(this->saldo > valor){
          this->saldo -= valor;
          Transacao x("15/10/2021", valor, "Transferência");
          this->transacoes.push_back(x);
          cont ++;
          conta << valor;
        }else{
          throw saldo_insuficiente_error();
        }
      }
      catch(saldo_insuficiente_error &e){
        cerr << e.what() << endl;
      }
    }

}

void Conta::operator>>(double valor){
  if(this->limite > 0){
    try{
    if(this->saldo > valor){
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
  }else{
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
}

void Conta::operator<<(double valor){
  if (valor > 0) this->saldo += valor;
  Transacao x("15/10/2021", valor, "Crédito");
  this->transacoes.push_back(x);
  cont++;
}