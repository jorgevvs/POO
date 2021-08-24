#ifndef IMOVELNOVO_H
#define IMOVELNOVO_H

#include "Imovel.h"

class ImovelNovo : public Imovel{
public:
    ImovelNovo(string, double, double);

    double getAdicional() const;
    void setAdicional(double);

    double getPreco() const;

private:
    double adicional;
};

#endif