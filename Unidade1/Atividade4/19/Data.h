#ifndef DATA_H
#define DATA_H

#include <string>
using std::string;

class Data
{
public:
    Data(int dia, int mes, int ano);

    int getDia();
    int getAno();
    int getMes();

    void setDia(int dia);
    void setMes(int mes);
    void setAno(int ano);

    string mostrarData();
    
private:
    int dataDia;
    int dataAno;
    int dataMes;
};

#endif