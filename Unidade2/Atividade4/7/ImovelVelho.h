#ifndef IMOVELVELHO_H
#define IMOVELVELHO_H

#include "Imovel.h"

class ImovelVelho : public Imovel{
public:
    ImovelVelho(string, double, double);

    double getDesconto() const;
    void setDesconto(double);

    double getPreco() const;

private:
    double desconto;
};

#endif