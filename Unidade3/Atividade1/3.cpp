#include <iostream>
#include <iomanip>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

int main(){
    char palavra[10];
    cout << "Digite a palavra: ";

    cin.getline(palavra, 10);

    int comprimento = strlen(palavra);

    cout << "Palavra digitada: " << std::setw(comprimento*2) << palavra << endl;
    cout << "Comprimento da palavra: " << comprimento << endl;

    return 0;
}
