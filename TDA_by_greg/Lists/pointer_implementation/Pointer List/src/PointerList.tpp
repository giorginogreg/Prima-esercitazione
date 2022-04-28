#include "../include/PointerList.h"

#include <stdio.h>  /* printf, scanf, NULL */
#include <stdlib.h> /* malloc, free, rand */


template<class TypeElems, int S>
PointerList<TypeElems, S>::PointerList() {
    auto nodeToInsert = new TDA_Greg::Node<TypeElems>();
    nodeToInsert->setNextPos(nullptr);
    nodeToInsert->setPrevPos(nullptr);
    _list = _tail = nodeToInsert;
    _max_nodes = S;
    initialize();
}

template<class T, int S>
PointerList<T, S>::PointerList(PointerList const &p) {

    auto nodeToInsert = new TDA_Greg::Node<T>();

    nodeToInsert->setNextPos(nullptr);
    nodeToInsert->setPrevPos(nullptr);
    _list = _tail = nodeToInsert;
    _max_nodes = p._max_nodes;
    initialize();

    PositionType sentinel_this = _list;
    PositionType _2head = p._list;
    while (!p.isLastPosition(_2head)) {
        _2head = _2head->getNextPos();
        insertNodeAfter(sentinel_this, _2head->getElem());
        sentinel_this = sentinel_this->getNextPos();
    }
}

template<class TypeElems, int S>
void PointerList<TypeElems, S>::initialize() {
    this->_elems_inside = 0;
}

template<class TypeElems, int S>
void PointerList<TypeElems, S>::writeValueAt(PositionType p, TypeElems t) {
    p->setElem(t);
}

template<class TypeElems, int S>
void PointerList<TypeElems, S>::insertNodeAfter(PositionType p, TypeElems t) {
    auto nodeToInsert = new TDA_Greg::Node<TypeElems>(t);

    nodeToInsert->setNextPos(p->getNextPos());
    nodeToInsert->setPrevPos(p);
    if(isLastPosition(p)) _tail = nodeToInsert;
    p->setNextPos(nodeToInsert);
    this->setElementsInside(this->getElementsInside() + 1);
}

template<class TypeElems, int S>
void PointerList<TypeElems, S>::deleteNodeAt(PositionType p) {
    p->getPrevPos()->setNextPos(p->getNextPos());

    if(!isLastPosition(p))
        p->getNextPos()->setPrevPos(p->getPrevPos());
    else
        delete p;

    this->setElementsInside(this->getElementsInside() - 1);
}

template<class TypeElems, int S>
TypeElems PointerList<TypeElems, S>::readValueAt(PositionType p) const {
    return p->getElem();
}

template<class TypeElems, int S>
bool PointerList<TypeElems, S>::isEmpty() const {
    return _list->getNextPos() == nullptr && _list->getPrevPos() == nullptr;
}

template<class TypeElems, int S>
bool PointerList<TypeElems, S>::isLastPosition(PositionType p) const {
    return p->getNextPos() == nullptr;
}

template<class TypeElems, int S>
Node<TypeElems>* PointerList<TypeElems, S>::firstNodeList() const {
    return _list->getNextPos();
}

template<class TypeElems,  int S>
Node<TypeElems>* PointerList<TypeElems, S>::nextPosition(PositionType p) const {
    return nullptr;
}

template<class TypeElems,  int S>
Node<TypeElems>* PointerList<TypeElems, S>::previousPosition(PositionType p) const {
    return nullptr;
}

template <typename TypeElems, int S>
PointerList<TypeElems, S>::~PointerList() {
    // In a dynamic list with pointers, it's needed to deallocate all the
    // list memory cells, iterating through each
    delete _list;
}

template<class T, int S>
bool PointerList<T, S>::find(T elem) {
    bool found = false;
    if(!isEmpty()) {
        auto head = _list;
        do {
            head = head->getNextPos();
            found = head->getElem() == elem;
        } while (!isLastPosition(head) && !found);
    }
    //delete head;
    return found;
}

template<class T, int S>
typename PointerList<T, S>::PositionType PointerList<T, S>::getFirstPositionByElem(T t) {
    auto head = _list;
    while (head != _tail){
        if( head->getElem() == t)
            break;
        head = head->getNextPos();
    }
    return head;
}
