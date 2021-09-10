#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios;

struct DADO{
    char tipo[10];
    int tamanho;
};

void salvaDados(){
    ofstream fout("dados.dat", ios::out);

    fout << "int" << ' ' << sizeof(int) << endl;
    fout << "double" << ' ' << sizeof(double) << endl;
    fout << "short" << ' ' << sizeof(short) << endl;
    fout << "long" << ' ' << sizeof(long) << endl;
    fout << "unsigned" << ' ' << sizeof(unsigned) << endl;
    fout << "signed" << ' ' << sizeof(signed) << endl;
    fout << "char" << ' ' << sizeof(char) << endl;
    fout << "bool" << ' ' << sizeof(bool) << endl;
    fout << "float" << ' ' << sizeof(float) << endl;
    fout << "longdouble" << ' ' << sizeof(long double) << endl;

    fout.close();
}

void exibeDados(){
    ifstream fin("dados.dat", ios::in);

    DADO x;
    cout << "  TIPO DE DADO           VALOR EM BYTE" << endl;

    while (fin >> x.tipo >> x.tamanho){
        cout << setw(12) << x.tipo << setw(20) << x.tamanho << endl;
    }
    fin.close();
}

int main(){
    salvaDados();
 
    exibeDados();

    return 0;
}