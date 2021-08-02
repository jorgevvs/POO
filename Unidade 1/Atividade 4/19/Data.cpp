#include <iostream>

#include <string>
#include "Data.h"

Data::Data(int dia, int mes, int ano){
    dataDia = dia;
    dataAno = ano;

    if (0 < mes && mes < 13) dataMes = mes;
    else dataMes = 1;
}

void Data::setDia(int dia){
    dataDia = dia;
}
void Data::setAno(int ano){
    dataAno = ano;
}
void Data::setMes(int mes){
    if (0 < mes && mes < 13)  dataMes = mes;
    else dataMes = 1;
}

int Data::getDia(){
    return dataDia;
}
int Data::getMes(){
    return dataMes;
}
int Data::getAno(){
    return dataAno;
}

string Data::mostrarData(){
    string data = std::to_string(dataDia) + "/" + std::to_string(dataMes) + "/" + std::to_string(dataAno);
    return data;
}