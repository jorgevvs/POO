#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using std::string;

class Animal{

public:
    Animal();
    Animal(string, string);


    string caminha() const;

protected:
    string nome;
    string raca;
};

#endif