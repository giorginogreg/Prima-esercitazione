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
    // In a dynamic list with pointers, it's needed to deallocate all the
    // list memory cells, iterating through each
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