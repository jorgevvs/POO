 #ifndef RETANGULO_H
 #define RETANGULO_H

class Retangulo
{
public:

    Retangulo();

    void setAltura(float alt);

    void setLargura(float larg);

    float getAltura();
    
    float getLargura();

    float perimetro();

    float area();

private:
    float altura;
    float largura;
};

#endif