#ifndef SALDO_INUFICIENTE_ERROR
#define SALDO_INUFICIENTE_ERROR

#include <stdexcept>
using std::out_of_range;

class saldo_insuficiente_error: public out_of_range{
public:
    saldo_insuficiente_error(const char*e = "Saldo Insuficiente!!!"): out_of_range(e){ }
};

#endif