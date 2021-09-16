#include <iostream>
#include <string>

using std::cout;
using std::endl;

template <class T, int size = 10>
class Fila{
public:
  Fila();
  ~Fila();

  void push(const T &val);
  void pop();
  void print();

private:
  T *posicao;
  int tam;
};

template <class T, int size>
Fila<T, size>::Fila(){
  tam = 0;
  posicao = new T[size];
}

template <class T, int size>
Fila<T, size>::~Fila()
{
  delete[] posicao;
}

template <class T, int size>
void Fila<T, size>::push(const T &val)
{
  if (tam < size){
    posicao[tam] = val;
    cout << "Inserindo " << posicao[tam] << endl;
    tam++;
  }
  else
    cout << "A Fila está cheia!!!" << endl;
}

template <class T, int size>
void Fila<T, size>::pop(){
  cout << "Removendo " << posicao[0] << " da fila" << endl;

  if (tam > 0){
    tam--;
    for(int i = 0; i < tam; i++){
      posicao[i] = posicao[i+1];
    }
  }

  else
    cout << "Fila vazia!!!" << endl;
}

template <class T, int size>
void Fila<T, size>::print(){
  for (int i = 1; i < tam + 1; i++)
    cout << i << ": " << posicao[i-1] << endl;

  cout << endl;
}