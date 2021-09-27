#ifndef PILHA_H
#define PILHA_H

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include <stdexcept>
using std::range_error;
using std::runtime_error;

template <class T>
class Pilha{
public:
    Pilha(int = 10);
    ~Pilha();

    bool push(const T &);
    bool pop(T &);

    bool isEmpty() const { return pos == 0; }
    bool isFull() const { return pos == tam; }

    void print();

private:
  T *pPtr;
  int pos, tam;
};

template <class T>
Pilha<T>::Pilha(int tam){
    this->tam = ((tam > 0) ? tam : 10);
    pos = 0;

    pPtr = new T[this->tam];
}

template <class T>
Pilha<T>::~Pilha(){
    delete[] pPtr;
}

template <class T>
bool Pilha<T>::push(const T &el){
    try
    {
        if (!isFull()){
        pPtr[pos++] = el;
        return true;
        }

        if (isFull()) throw runtime_error("A Pilha está cheia!");
    }
    catch (runtime_error &e){
        cerr << e.what() << endl;
        return false;
  }
  return true;
}

template <class T>
bool Pilha<T>::pop(T &el){
    try{
        if (!isEmpty()){
        el = pPtr[--pos];
        return true;
        }

        if (isEmpty()) throw runtime_error("A Pilha está vazia!");
    }
    catch (runtime_error &e){
        cerr << e.what() << endl;
        return false;
    }
    return true;
}

template <class T>
void Pilha<T>::print(){
  for (int i = 0; i < tam; i++){
    cout << this->pPtr[i] << endl;
  }
}

#endif