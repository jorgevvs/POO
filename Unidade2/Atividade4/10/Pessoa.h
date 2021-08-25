#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using std::string;

#include <iostream>
using std::ostream;

class Pessoa{
    friend ostream& operator<<(ostream&, const Pessoa);
public:
    Pessoa();
    Pessoa(string);

    string getNome() const;
    void setNome(string);


protected:
    string nome;
};


#endif