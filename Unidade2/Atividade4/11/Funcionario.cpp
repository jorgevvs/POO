#include "Funcionario.h"

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;


ostream& operator<<(ostream& out, Funcionario x){
    cout << "===========================================\n";
    cout << "Funcionario : " << x.getNome() << " \nCPF: " << x.getCPF() << " \nMatricula: " << x.getMatricula() << " \nSalario Bruto: " << x.calculaSalarioBruto() << endl;
    return out;
}

Funcionario::Funcionario(){
    this->nome = "";
    this->cpf = 0;
    this->matricula = 0;
    this->salario = 0;
    this->cargaHoraria = 0;
    this->horasTrab = 0;
}

Funcionario::Funcionario(string nome, long int cpf, int matricula, double salario, int cargaHoraria, int horasTrab) : PessoaFisica(nome, cpf), matricula(matricula), salario(salario), cargaHoraria(cargaHoraria), horasTrab(horasTrab){
    this->nome = nome;
    this->cpf = cpf;
    this->matricula = matricula;
    this->salario = salario;
    this->cargaHoraria = cargaHoraria;

    if(horasTrab > cargaHoraria) this->horasTrab = cargaHoraria;
    if(horasTrab <= 0) this->horasTrab = 0;
    else this->horasTrab = horasTrab;
}

float Funcionario::calculaSalarioBruto(){
    float salarioTotal = (getHorasTrab() + 0.0) / (getCargaHoraria() + 0.0);
    salarioTotal = salarioTotal * getSalario();
    return salarioTotal;
}

int Funcionario::getMatricula() const{
    return this->matricula;
}

void Funcionario::setMatricula(int num){
    this->matricula = num;
}

double Funcionario::getSalario() const{
    return this->salario;
}

void Funcionario::setSalario(double num){
    this->salario = num;
}

int Funcionario::getCargaHoraria() const{
    return this->cargaHoraria;
}

void Funcionario::setCargaHoraria(int num){
    this->cargaHoraria = num;
}

int Funcionario::getHorasTrab() const{
    return this->horasTrab;
}

void Funcionario::setHorasTrab(int num){
    if(num > this->cargaHoraria){
        this->horasTrab = getCargaHoraria();
    }else if(num <= 0) this->horasTrab = 0;
    else this->horasTrab = num;
}