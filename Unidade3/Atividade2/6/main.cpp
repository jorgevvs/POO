#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;

#include "Array.h"

int main() {
    Array<int> ai1(5);
    Array<int> ai2(5);

    ai1[0] = 55;
    ai1[1] = 65;
    ai1[2] = 24;
    ai1[3] = 45;
    ai1[4] = 8;

    ai2[0] = 55;
    ai2[1] = 65;
    ai2[2] = 24;
    ai2[3] = 45;
    ai2[4] = 8;

    cout << ai1; 
    cout << ai2;   

    cout <<"ai1 e ai2 são iguais?: "<< (ai1 == ai2) << endl;


    Array<string> as1(4);

    as1[0] = "I";
    as1[1] = "F";
    as1[2] = "P";
    as1[3] = "B";

    cout << as1;

    Array<double> ad1(5);

    ad1[0] = 50.5;
    ad1[1] = 14.74;
    ad1[2] = 26.67;
    ad1[3] = 833.66;
    ad1[4] = 0.555;

    cout << ad1;

    return 0;
}