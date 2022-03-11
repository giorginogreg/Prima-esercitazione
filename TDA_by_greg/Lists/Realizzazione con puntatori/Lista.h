
#ifndef List_H_
#define List_H_

#include "../Nodo.h"
using namespace TDA_Greg;

// Insieme di nodi
template <typename T>
class List
{
    using P = *T;

private:
    Nodo<T> *nodi;
    int numNodi = 100;

public:
    List(); // Default constructor - Equal to create operator
    List(int numElem);

    this writeValue(P pos, T elem);
    this insert(P pos, T elem);
    this deleteElem(P pos);

    T readValue(P pos);
    bool isEmpty();
    bool isLastValue(P pos);
    T firstNodeList();
    P nextValue(P pos);
    P prevValue(P pos);
};

#endif