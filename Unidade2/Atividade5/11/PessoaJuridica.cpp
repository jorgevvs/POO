#include <iostream>
using std::cout;
using std::endl;
using std::string;

#include "PessoaJuridica.h"
#include "Pessoa.h"

PessoaJuridica::PessoaJuridica(string nome, string endereco, string email, string cnpj, int inscricaoEstadual, string razaoSocial) : Pessoa( nome, endereco, email){
    this->cnpj = cnpj;
    this->inscricaoEstadual = inscricaoEstadual;
    this->razaoSocial = razaoSocial;
}

void PessoaJuridica::exibirPessoa() const{
    cout << "====== Pessoa Juridica =======" << endl;
    cout << "Nome: " << this->getNome() << endl;
    cout << "Endereço: " << this->getEndereco() << endl;
    cout << "Email: " << this->getEmail() << endl;
    cout << "CNPJ: " << this->getCpforCNPJ() << endl;
    cout << "Inscrição Estadual: " << this->getInscricaoEstadual() << endl;
    cout << "Razão Social: " << this->getRazaoSocial() << endl;
    cout << "==============================\n" << endl;
}
