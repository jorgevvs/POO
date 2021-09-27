#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cerr;

#include <stdexcept>
using std::range_error;
using std::runtime_error;

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
void Fila<T, size>::push(const T &val){

    try{
    if (tam < size){
        posicao[tam] = val;
        cout << "Inserindo " << posicao[tam] << endl;
        tam++;
    }
    else throw runtime_error("Fila Cheia!");
    }
    catch(runtime_error &e){
        cerr << e.what() << endl;
    }
}

template <class T, int size>
void Fila<T, size>::pop(){
  
    try{
    if (tam > 0){
        cout << "Removendo " << posicao[0] << " da fila" << endl;
        tam--;
        for(int i = 0; i < tam; i++){
        posicao[i] = posicao[i+1];
        }
    }

    else throw runtime_error("Fila Vazia!");
    }
    catch (runtime_error &e){
        cerr << e.what() << endl;
    }
}

template <class T, int size>
void Fila<T, size>::print(){
  for (int i = 1; i < tam + 1; i++)
    cout << i << ": " << posicao[i-1] << endl;

  cout << endl;
}