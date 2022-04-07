#include "../include/PointerList.h"

#include <stdio.h>  /* printf, scanf, NULL */
#include <stdlib.h> /* malloc, free, rand */

/*template <typename TypeElems>
List<TypeElems>::List()
{
    numNodi = 0;
    nodi = NULL;
}

template <typename TypeElems>
List<TypeElems>::List(int numElem)
{
    if (numElem > 0)
    {
        nodi = (Nodo<TypeElems> *)malloc(sizeof(Nodo<TypeElems>) * numElem);
        numNodi = numElem;
    }
}
*/

template <typename TypeElems, int S>
PointerList<TypeElems, S>::~PointerList() {
    // In a dynamic list with pointers, it's needed to deallocate all the
    // list memory cells, iterating through each
}


template<class TypeElems, int S>
void PointerList<TypeElems, S>::initialize() {
}

template<class TypeElems, int S>
void PointerList<TypeElems, S>::writeValueAt(P p, TypeElems t) {
    p->setElem(t);
}

template<class TypeElems, int S>
void PointerList<TypeElems, S>::insertNodeAfter(P p, TypeElems t) {
    auto nodeToInsert = new TDA_Greg::Node<TypeElems>(t);

    nodeToInsert->setNextPos(p->getNextPos());
    nodeToInsert->setPrevPos(p);
    p->setNextPos(nodeToInsert);
    this->setElementsInside(this->getElementsInside() + 1);
}

template<class TypeElems, int S>
void PointerList<TypeElems, S>::deleteNodeAt(P p) {

}

template<class TypeElems, int S>
TypeElems PointerList<TypeElems, S>::readValueAt(P p) {
    return nullptr;
}

template<class TypeElems, int S>
bool PointerList<TypeElems, S>::isEmpty() {
    return false;
}

template<class TypeElems, int S>
bool PointerList<TypeElems, S>::isLastValue(P p) {
    return false;
}

template<class TypeElems, int S>
Node<TypeElems>* PointerList<TypeElems, S>::firstNodeList() {
    return nullptr;
}

template<class TypeElems,  int S>
Node<TypeElems>* PointerList<TypeElems, S>::nextPosition(P p) {
    return nullptr;
}

template<class TypeElems,  int S>
Node<TypeElems>* PointerList<TypeElems, S>::previousPosition(P p) {
    return nullptr;
}

