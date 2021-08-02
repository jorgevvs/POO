#ifndef CUPOM_H
#define CUPOM_H

#include <string>
using std::string;

class Cupom
{
public:
    Cupom(string id, string description, int quant, float preco);
    
    void setId(string id);
    void setDesc(string desc);
    void setQuant(int quant);
    void setPreco(float preco);

    string getId();
    string getDesc();
    int getQuant();
    float getPreco();

    float calculaCupom();


private:
    string cupomId;
    string cupomDesc;
    int cupomQuant;
    float cupomPreco;
};

#endif