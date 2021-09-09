#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setprecision;


double conversor(int temp){
    double newTemp = double(5.0 / 9.0 * ( temp  - 32));
    return newTemp;
}

int main(){
    int tempFaren = 62;

    cout << "Temperatura em Fahrenheit: " << std::setw(7)<< tempFaren << "°F" <<endl;
    cout << "Temperatura em Celsius: " << std::fixed << setprecision(3) << std::setw(10) << conversor(tempFaren) <<"°C" << endl;
    

    return 0;
}; // g++ -Wall -std=c++17 main.cpp -o main && ./main

