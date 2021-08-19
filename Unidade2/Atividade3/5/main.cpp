#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "Array.h"

int main() {
  Array a1(3);  //array de 7 elementos
  Array a2(3);     //array de 10 elementos

  cin >> a1;    //lendo array 
  cin >> a2;

  Array a3 = a1 + a2; // Criando array 3 sendo a soma do array 1 mais o 2

  a1 += a2; // Somando array 1 com o 2;

  cout << a1;
  cout << a3;

  return 0;
} // g++ -Wall -std=c++17 main.cpp Array.cpp -o main && ./main