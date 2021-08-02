#include <iostream>

#include <string>
#include "Empregado.h"

Empregado::Empregado(string nome, string sobrenome, double salario){
    nomeEmpregado = nome;
    sobrenomeEmpregado = sobrenome;

    if(salario > 0) salMensal = salario;
    else salMensal = 0;
}

void Empregado::setNome(string nome){
    nomeEmpregado = nome;
}

void Empregado::setSobrenome(string nome){
    sobrenomeEmpregado = nome;
}
void Empregado::setSal(double salario){
    salMensal = salario;
}

string Empregado::getNome(){
    return nomeEmpregado;
}

string Empregado::getSobrenome(){
    return sobrenomeEmpregado;
}

double Empregado::getSal(){
    return salMensal;
}


