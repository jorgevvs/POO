#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "FormaBidimensional.h"

#include <iostream>
using std::cout;
using std::endl;

class Triangulo : public FormaBidimensional
{
public:
  Triangulo(double base, double altura) : FormaBidimensional(3), base(base), altura(altura) {}

  virtual void desenhar() {
    cout << "  .   " << endl;
    cout << " / \\ " << endl;
    cout << "/   \\" << endl;
    cout << "~~~~~ " << endl;
  }

  virtual double calcularArea(){
    return (this->base * this->altura) / 2;
  }

  virtual double calcularPerimetro(){
    return this->base * this->numLados;
  }
private:
  double base, altura;

};

#endif