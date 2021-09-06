#include "Pessoa.h"
#include "PessoaFisica.h"
#include "PessoaJuridica.h"
#include "Agenda.h"

#include <iostream>
using std::cout;
using std::endl;

int main(){
    Agenda agenda(5);

    agenda.adicionaContato(new PessoaFisica("Sirius Black", "Rua dos Almofadinhas", "sirius@black.com", "12352362387", "07/06/2002", "Solteiro"));
    agenda.adicionaContato(new PessoaFisica("Aurora Gilliard", "Rua Santo André", "auroragil125@gmail.com", "15234573612", "30/01/1985", "Casada"));
    agenda.adicionaContato(new PessoaFisica("Steve Rogers", "Brooklyn, Sesame Street", "captainamerica@gmail.com", "52897356111", "04/07/1918", "Solteiro"));
    agenda.adicionaContato(new PessoaJuridica("Industrias Stark", "Rua Barão do Rio Branco", "main@starkindustries.com", "8729532000152", 984632, "Industrias Tecnológicas"));
    agenda.adicionaContato(new PessoaJuridica("Wayne Enterprises", "Rua do Matadouro", "bruce@wayneinc.com", "8729532000152", 984632, "Industria Multinacional"));

    agenda.printAgenda();
    agenda.removeContato("Wayne Enterprises");
    agenda.removeContato("15234573612");
    agenda.buscaContato("Wayne Enterprises");
    agenda.buscaContato("15234573612");

  return 0;
} // g++ -Wall -std=c++17 main.cpp Agenda.cpp PessoaFisica.cpp PessoaJuridica.cpp -o main && ./main