#ifndef CARRO_H
#define CARRO_H

#include <string>

using std::string;

class Carro
{

public:
    Carro(string nome, int anoCarro);

    void setMarca(string nome);

    void setAno(int anoCarro);

    int getAno();

    string getMarca();

    void displayMessage();

private:
    string marca;
    int anoCarro;

};
#endif