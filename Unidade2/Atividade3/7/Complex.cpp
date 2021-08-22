#include "Complex.h"

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

Complex::Complex(double real, double img){
  this->real = real;
  this->img = img;
}

const Complex& Complex::operator+(const Complex& complex2) const {
  double parteReal = this->real + complex2.real;
  double parteImg = this->img + complex2.img;

  Complex *complex3= new Complex(parteReal, parteImg);

  return *complex3;
}

const Complex& Complex::operator-(const Complex& complex2) const {
  double parteReal = this->real - complex2.real;
  double parteImg = this->img - complex2.img;

  Complex *complex3 = new Complex(parteReal, parteImg);

  return *complex3;
}

const void Complex::operator+=(const Complex& complex2){
  this->real += complex2.real;
  this->img += complex2.img;

}

const void Complex::operator-=(const Complex& complex2){
  this->real -= complex2.real;
  this->img -= complex2.img;
}

Complex &Complex::operator++(){
  this->real++;
  return *this;
}

Complex Complex::operator++(int){
  Complex aux = *this;
  this->real++;
  return aux;
}

Complex &Complex::operator--(){
  this->real--;
  return *this;
}

Complex Complex::operator--(int){
  Complex aux = *this;
  this->real--;
  return aux;
}

ostream& operator<<(ostream& out, const Complex& number){
  cout << number.real << " + " << number.img << "i" << endl;
  return out;
}