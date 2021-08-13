#ifndef INTEGERSET_H
#define INTEGERSET_H


class IntegerSet{

    friend IntegerSet unionOfSets(IntegerSet x, IntegerSet y);

    friend IntegerSet intersetionOfSets(IntegerSet x, IntegerSet y);


public:
    IntegerSet();
    IntegerSet(int [], int tamanho);

    void insertElement(int x);
    void deleteElement(int x);

    void print() const;

private:
    int array[100];
};
#endif