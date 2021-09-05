#ifndef CIRCULO_H
#define CIRCULO_H

#include "FormaBidimensional.h"

#include <iostream>
using std::cout;
using std::endl;

class Circulo : public FormaBidimensional
{
public:
  Circulo(double raio) : FormaBidimensional(99999), raio(raio) {}

  virtual void desenhar() {
    cout << "  _ " << endl;
    cout << "/   \\" << endl;
    cout << "\\   /" << endl;
    cout << "  ~ " << endl;
  }

    virtual double calcularArea(){
      return (this->raio * this->raio) * 3.14;
    }

    virtual double calcularPerimetro(){
      return 2 * 3.14 * this->raio;
    }
private:
  double raio;
};

#endif