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

    vector<Conta> listaContas;

    listaContas.push_back(c1);
    listaContas.push_back(c2);

    listaContas[0].extrato();

    for(auto &el : listaContas){
        cout << el.getSaldo() << endl;
    }

    return 0;
}