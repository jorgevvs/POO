#include <iostream>
using namespace std;

int main(void){
    double kilometros = 0.0, litros, consumo, litrosTotais;



    while(kilometros != -1){
        cout << "Digite a quantidade de kilometros percorrida:" << endl;

        cin >> kilometros;

        if(kilometros == -1){
            break;
        }

        cout << "Digite a quantidade de litros consumidos:" << endl;
        cin >> litros;
        consumo = kilometros/litros;
        litrosTotais += litros;
        cout << "O consumo de seu tanque foi de " << consumo << "km/l \nSua utilização até agora foi de: "<< litrosTotais << " litros\n" << endl; 
    }









    return 0;
}