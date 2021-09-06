#include <iostream>
using std::cout;
using std::endl;
using std::string;

#include "PessoaFisica.h"
#include "Pessoa.h"

PessoaFisica::PessoaFisica(string nome, string endereco, string email, string cpf, string dataDeNascimento, string estadoCivil) : Pessoa( nome, endereco, email){
    this->cpf = cpf;
    this->dataDeNascimento = dataDeNascimento;
    this->estadoCivil = estadoCivil;
}


void PessoaFisica::exibirPessoa() const{
    cout << "======= Pessoa Fisica ========" << endl;
    cout << "Nome: " << this->getNome() << endl;
    cout << "Endereço: " << this->getEndereco() << endl;
    cout << "Email: " << this->getEmail() << endl;
    cout << "CPF: " << this->getCpforCNPJ() << endl;
    cout << "Data de Nascimento: " << this->getDataDeNascimento() << endl;
    cout << "Estado Civil: " << this->getEstadoCivil() << endl;
    cout << "=============================\n" << endl;
}