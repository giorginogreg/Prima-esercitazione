#include "Nodo.h"
#include "Lista.h"

#include <stdio.h>  /* printf, scanf, NULL */
#include <stdlib.h> /* malloc, free, rand */
template <typename T>
Lista<T>::Lista()
{
    numNodi = 0;
    nodi = NULL;
}

template <typename T>
Lista<T>::Lista(int numElem)
{
    if (numElem > 0)
    {
        nodi = (Nodo<T> *)malloc(sizeof(Nodo<T>) * numElem);
        numNodi = numElem;
    }
}

//Lista &Lista::operator=(const &Lista l);
/* 
Lista::addNodo(Nodo n)
{
    this->nodi[] = n;
}

Lista::isEmpty()
{
    return this->numNodi == 0;
}

;
 */