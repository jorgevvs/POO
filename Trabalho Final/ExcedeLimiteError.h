#ifndef EXCEDE_LIMITE_ERROR
#define EXCEDE_LIMITE_ERROR

#include <stdexcept>
using std::out_of_range;

class ExcedeLimite: public out_of_range{
public:
    ExcedeLimite(const char*e = "Excedeu o limite!!"): out_of_range(e){ }
};

#endif