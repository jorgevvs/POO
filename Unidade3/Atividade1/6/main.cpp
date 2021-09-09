#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <fstream>
using std::ifstream;
using std::ofstream;

struct TIPOS_DADOS{
    char dado[15];
    int byte;
};


void salvaDados(TIPOS_DADOS c[], int n){
    ofstream fout("tiposDeDados.dat", std::ios::out);

    for (int i = 0; i < n; i++)
        fout << c[i].byte << ' ' << c[i].dado << endl;

    fout.close();
}

void exibeDados(){
    ifstream fin("tiposDeDados.dat", std::ios::in);
    TIPOS_DADOS c;

    cout << "  TIPO DE DADO           VALOR EM BYTE" << endl;

    while (fin >> c.byte >> c.dado){
        cout << setw(10) << c.dado << setw(22) << c.byte  << endl;
    }
    fin.close();
}

int main(){
    TIPOS_DADOS dados[10] = {
    {"int", sizeof(int)},
    {"double", sizeof(double)},
    {"short", sizeof(short)},
    {"long", sizeof(long)},
    {"unsigned", sizeof(unsigned)},
    {"signed", sizeof(signed)},
    {"char", sizeof(char)},
    {"bool", sizeof(bool)},
    {"float", sizeof(float)},
    {"longdouble", sizeof(long double)}
    };

    salvaDados(dados, 10);

    exibeDados();

    return 0;
}