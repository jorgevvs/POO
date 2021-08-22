#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using std::ostream;

class Complex {
  friend ostream& operator<<(ostream&, const Complex&);
public:
  Complex(double,double);

  const Complex& operator+(const Complex&) const;
  const Complex& operator-(const Complex&) const;

  const void operator+=(const Complex&);
  const void operator-=(const Complex&);

  Complex &operator++();
  Complex operator++(int);

  Complex &operator--();
  Complex operator--(int);

private:
  double real, img;
};

#endif