#include <iostream>
using std::cout;
using std::endl;

#include "ContaComum.h"
#include "ContaLimite.h"
#include "ContaPoupanca.h"
#include "Conta.h"
#include "PessoaFisica.h"
#include "PessoaJuridica.h"
#include "Pessoa.h"
#include "Banco.h"

#include <list>
using std::list;

#include <vector>
using std::vector;

int main(){
    PessoaFisica p1("Thales Luiz", 22642763812);
    PessoaJuridica p2("Robertinho" , 5283755323, "LGTB");

    ContaComum c1(420131, p1, 5050.50);
    ContaLimite c2(52526, p2, 1000.50, 500.00);
    
    list<Pessoa> lista;

    lista.push_back(p1);
    lista.push_back(p2);

    for(auto &el : lista){
        cout << el.getNome() << endl;
    }
    int x= 0;

    list<Conta> listaConta;

    listaConta.push_back(c1);
    listaConta.push_back(c2);

    
    for(auto &el : listaConta){
        if(el.getNumero() == 420131)
            x +=1;
    }
    cout << x << endl;


    c1 << 1000;
    c1.extrato();

    return 0;
}