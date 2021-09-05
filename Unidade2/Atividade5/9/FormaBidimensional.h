#ifndef FORMABI_H
#define FORMABI_H 

//classe abstrata

class FormaBidimensional 
{
public:
  FormaBidimensional(int numLados) : numLados(numLados) { }

  virtual ~FormaBidimensional(){}

  //método virtual puro
  virtual void desenhar() = 0;
  
  virtual double calcularArea() = 0;
  virtual double calcularPerimetro() = 0;

protected:
  int numLados;
};

#endif