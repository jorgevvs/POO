#include <iostream>

#include "Agenda.h"


int main () {
	char linha[] = "---------------------------------------------\n";
	Agenda A(2);

	A.armazenaPessoa("Abel", 22, 1.78);
	A.armazenaPessoa(Pessoa("Tiago", 20, 1.80));
	A.imprimePovo();
	std::cout << linha;

	int posicao = A.buscaPessoa("Tiago");
	if (posicao > 0)
    	A.imprimePessoa(posicao);
	std::cout << linha;

	A.removePessoa("Tiago");

	A.imprimePovo();
	std::cout << linha;
	

 	return 0;
} //g++ -Wall -std=c++17 main.cpp Agenda.cpp Pessoa.cpp -o main && ./main