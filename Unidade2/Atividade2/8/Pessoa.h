#ifndef PESSOA_H
#define PESSOA_H


#include <string>
using std::string;

class Pessoa
{
public:
    Pessoa(string name,int age, float height);

    void setNome(string name);
    void setIdade(int age);
    void setAltura(float height);

    inline string getNome() const {return nome;}
    inline int getIdade() const {return idade;}
    inline float getAltura() const {return altura;}

    void imprimePessoa() const;


private:
    string nome;
    int idade;
    float altura;
};

#endif