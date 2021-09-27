#ifndef EXCECAO_DERIV
#define EXCECAO_DERIV

#include <stdexcept>
using std::runtime_error;

class ExcecaoDerivada : public runtime_error {
public:
  ExcecaoDerivada(const char* e="Lançando Exceção!") : runtime_error(e){}
};

#endif 