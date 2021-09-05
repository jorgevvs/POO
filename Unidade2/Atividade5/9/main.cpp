#include <iostream>

#include "Quadrado.h"
#include "Circulo.h"
#include "Triangulo.h"


int main() {
  //FormaBidimensional fd(2); // ERRO!!!!

  FormaBidimensional *formas[] = {new Quadrado(10.5), new Circulo(5), new Triangulo(12, 10.39)};

  for (int i = 0 ; i < 3 ; i++){
    formas[i]->desenhar();
    cout << "Area: " << formas[i]->calcularArea() << endl;
    cout << "Perimetro: " << formas[i]->calcularPerimetro() << endl;
    delete formas[i];
  }

  return 0;
}