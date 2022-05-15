#include "../include/PointerList.h"

#include <stdio.h>  /* printfcanf, NULL */
#include <stdlib.h> /* malloc, free, rand */


template<class TypeElems>
PointerList<TypeElems>::PointerList(int numMaxElems) {
    auto nodeToInsert = new TDA_Greg::Node<TypeElems>();
    nodeToInsert->setNextPos(nullptr);
    nodeToInsert->setPrevPos(nullptr);
    _list = _tail = nodeToInsert;
    initialize(numMaxElems);
}

template<class T>
PointerList<T>::PointerList(PointerList const &p) {

    auto nodeToInsert = new TDA_Greg::Node<T>();

    nodeToInsert->setNextPos(nullptr);
    nodeToInsert->setPrevPos(nullptr);
    _list = _tail = nodeToInsert;
    initialize(p._max_elems_inside);

    PositionType sentinel_this = _list;
    PositionType _2head = p._list;
    while (!p.isLastPosition(_2head)) {
        _2head = _2head->getNextPos();
        insertNodeAfter(sentinel_this, _2head->getElem());
        sentinel_this = sentinel_this->getNextPos();
    }
}

template<class TypeElems>
void PointerList<TypeElems>::initialize(int maxElemsInside) {
    this->_elems_inside = 0;
    LinearList<TypeElems, PositionType>::initialize(maxElemsInside);
}

template<class TypeElems>
void PointerList<TypeElems>::writeValueAt(PositionType p, TypeElems t) {
    p->setElem(t);
}

template<class TypeElems>
void PointerList<TypeElems>::insertNodeAfter(PositionType p, TypeElems t) {
    auto nodeToInsert = new TDA_Greg::Node<TypeElems>(t);

    nodeToInsert->setNextPos(p->getNextPos());
    nodeToInsert->setPrevPos(p);
    if(isLastPosition(p)) _tail = nodeToInsert;
    p->setNextPos(nodeToInsert);
    this->setElementsInside(this->getElementsInside() + 1);
}

template<class TypeElems>
void PointerList<TypeElems>::deleteNodeAt(PositionType p) {
    p->getPrevPos()->setNextPos(p->getNextPos());

    if(!isLastPosition(p))
        p->getNextPos()->setPrevPos(p->getPrevPos());
    else
        delete p;

    this->setElementsInside(this->getElementsInside() - 1);
}

template<class TypeElems>
TypeElems PointerList<TypeElems>::readValueAt(PositionType p) const {
    return p->getElem();
}

template<class TypeElems>
bool PointerList<TypeElems>::isEmpty() const {
    return _list->getNextPos() == nullptr && _list->getPrevPos() == nullptr;
}

template<class TypeElems>
bool PointerList<TypeElems>::isLastPosition(PositionType p) const {
    return p->getNextPos() == nullptr;
}

template<class TypeElems>
Node<TypeElems>* PointerList<TypeElems>::firstNodeList() const {
    return _list->getNextPos();
}

template<class TypeElems>
Node<TypeElems>* PointerList<TypeElems>::nextPosition(PositionType p) const {
    return p->getNextPos();
}

template<class TypeElems>
Node<TypeElems>* PointerList<TypeElems>::previousPosition(PositionType p) const {
    return p->getPrevPos();
}

template <typename TypeElems>
PointerList<TypeElems>::~PointerList() {
    // In a dynamic list with pointers, it's needed to deallocate all the
    // list memory cells, iterating through each
    delete _list;
}

template<class T>
bool PointerList<T>::find(T elem) {
    bool found = false;
    if(!isEmpty())
      found = getFirstPositionByElem(elem) != nullptr;

    return found;
}

/**
 * Can return nullptr if the element is not found, or the position otherwise
 * @tparam T
 * @param t
 * @return
 */
template<class T>
typename PointerList<T>::PositionType PointerList<T>::getFirstPositionByElem(T t) {
    auto head = _list;
    while (!isLastPosition(head)) {
        head = nextPosition(head);
        if(readValueAt(head) == t)
            return head;
    }
    return nullptr;
}
