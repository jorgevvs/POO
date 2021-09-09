#include <iostream>
using std::cout; using std::endl;

#include <iomanip>
using std::setprecision;

int main() {
  double num = 100.453627;

 
    cout << "Numero com 1 casa decimal: "<< setprecision(4) << num <<endl;

    cout.precision(5);
    cout << "Numero com 2 casas decimais: "<<  num <<endl;

    cout << "Numero com 3 casas decimais: "<<  setprecision(6) << num <<endl;

    cout.precision(7);
    cout << "Numero com 4 casas decimais: "<<  num <<endl;

  

  return 0;
}