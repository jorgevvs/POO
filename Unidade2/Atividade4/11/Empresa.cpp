#include "Empresa.h"

#include <string>
using std::string;
using std::cout;


Empresa::Empresa(){
    this->nome = "";
    this->cnpj = 523562000152;
    this->razao = "";
}

Empresa::Empresa(string nome, long int cnpj, string razao) : PessoaJuridica(nome,cnpj,razao){
    this->nome = nome;
    this->cnpj = cnpj;
    this->razao = razao;
}

void Empresa::adicionaCliente(Cliente const cliente){
    if (this-> quantClientes != 10){
        this-> clientes[this->quantClientes] = cliente;  
        this-> quantClientes++;
    } 
}

void Empresa::adicionaFuncionario(Funcionario const funcionario){
    if (this-> quantFuncionarios != 10){
        this-> funcionarios[this->quantFuncionarios] = funcionario;
        this-> quantFuncionarios++;
    } 
}

void Empresa::imprimeClientes() const{
    cout << "\n================ Clientes =================\n" << std::endl;
    for(int i = 0; i < this->quantClientes; i++){
        cout << clientes[i];
    }
}

void Empresa::imprimeFuncionarios() const{
    cout << "\n=============== Funcionarios ===============\n" << std::endl;
    for(int i = 0; i < this->quantFuncionarios; i++){
        cout << funcionarios[i];
    }
}

double Empresa::calcularFolhaDePagamento(){
    double totalGasto = 0.0;
    for(int i = 0; i < this-> quantFuncionarios; i++){
        totalGasto += funcionarios[i].calculaSalarioBruto();
    }
}
