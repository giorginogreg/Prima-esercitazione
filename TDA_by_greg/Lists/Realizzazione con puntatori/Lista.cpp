#include "Nodo.h"
#include "Lista.h"

#include <stdio.h>  /* printf, scanf, NULL */
#include <stdlib.h> /* malloc, free, rand */
template <typename T>
List<T>::List()
{
    numNodi = 0;
    nodi = NULL;
}

template <typename T>
List<T>::List(int numElem)
{
    if (numElem > 0)
    {
        nodi = (Nodo<T> *)malloc(sizeof(Nodo<T>) * numElem);
        numNodi = numElem;
    }
}

template <typename T>
List<T>::~List() {
//Lista &Lista::operator=(const &Lista l);
}

//List &List::operator=(const &List l);
/* 
List::addNodo(Nodo n)
{
    this->nodi[] = n;
}

List::isEmpty()
{
    return this->numNodi == 0;
}

;
 */