#include "../include/PointerList.h"

#include <stdio.h>  /* printf, scanf, NULL */
#include <stdlib.h> /* malloc, free, rand */

/*template <typename T>
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
}*/

template <typename T, class P, int S>
PointerList<T, P, S>::~PointerList() {
    // In a dynamic list with pointers, it's needed to deallocate all the
    // list memory cells, iterating through each
}


template<class T, class P, int S>
void PointerList<T, P, S>::initialize() {

}

template<class T, class P, int S>
void PointerList<T, P, S>::writeValueAt(int i, T t) {

}

template<class T, class P, int S>
void PointerList<T, P, S>::insertNodeAfter(P p, T t) {

}

template<class T, class P, int S>
void PointerList<T, P, S>::deleteNodeAt(P p) {

}

template<class T, class P, int S>
T PointerList<T, P, S>::readValueAt(P p) {
    return nullptr;
}

template<class T, class P, int S>
bool PointerList<T, P, S>::isEmpty() {
    return false;
}

template<class T, class P, int S>
bool PointerList<T, P, S>::isLastValue(P p) {
    return false;
}

template<class T, class P, int S>
P PointerList<T, P, S>::firstNodeList() {
    return nullptr;
}

template<class T, class P, int S>
P PointerList<T, P, S>::nextPosition(P p) {
    return nullptr;
}

template<class T, class P, int S>
P PointerList<T, P, S>::previousPosition(P p) {
    return nullptr;
}

