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
    PessoaFisica p1("ThalesLuiz", 22642763812);
    PessoaJuridica p2("Robertinho" , 5283755323, "LGTB");

    ContaComum c1(420131, p1, 5050.50);
    ContaLimite c2(52526, p2, 1000.50, 500.00);
    ContaPoupanca c3(52526532, p2, 2000.50, 30);

    Banco b1("BB", 5123125, "Banco do Brasil");

    b1.cadastrarConta(c1);
    b1.cadastrarConta(c2);
    b1.cadastrarConta(c3);

    b1.listarContasCorrentista(p2);

    return 0;
}