#include <iostream>
using std::cout;
using std::endl;

#include "Time.h"

int main() {
  //ex1 
  Time t;
  t.setTime(23,59,59);

  for(int i=0; i < 62; i++){
      t.printUniversal();
      t.tick();
  }
  
  return 0;
} // g++ -Wall -std=c++17 main.cpp Time.cpp -o main && ./main