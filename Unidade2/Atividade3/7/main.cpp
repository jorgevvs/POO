#include <iostream>
using std::cout;

#include "Complex.h"

int main(){
  Complex n1(2, 2);
  Complex n2(-5, 10);
  Complex n3 = n1 + n2;
  Complex n4(20,5);

  cout << "n1: " << n1 << "n2: " << n2 << "n3: " << n3 << "n4: " << n4;

  cout<< "\nSomando 1 ao n1 e diminuindo 1 do n2...\n";
  n1++;
  n2--;
  cout << "n1: " << n1 << "n2: " << n2;


  cout << "Somando n1 ao n1...";
  n1 += n1;
  cout << "n1: " << n1;

  cout << "\nDiminuindo n3 do n4...";
  n4 -= n3;


  cout <<"\nn4: " <<  n4;



  return 0;
} // g++ -Wall -std=c++17 main.cpp Complex.cpp -o main && ./main
