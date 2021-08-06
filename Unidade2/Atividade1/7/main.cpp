#include <iostream>
using std::cout;
using std::endl;

#include "Time.h"

//o uso de métodos inline não alteram a lógica do programa
int main() {
  Time t1, t2(23);

  cout << "Horário atual t1: ";
  t1.printUniversal();

  cout << "Horário apenas declarando hora t2: ";
  t2.printUniversal();


  return 0;
} // g++ -Wall -std=c++17 main.cpp Time.cpp -o main && ./main