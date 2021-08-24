#ifndef IMOVEL_H
#define IMOVEL_H

#include <string>
using std::string;

class Imovel{
public:   

    Imovel();
    Imovel(string, double);

    string getEndereco() const;
    double getPreco() const;

    void setPreco(double);
    void setEndereco(string);


protected:
    string endereco;
    double preco;

};

#endif