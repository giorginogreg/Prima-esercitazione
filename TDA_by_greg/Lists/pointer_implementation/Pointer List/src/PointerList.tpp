#include "../include/PointerList.h"

#include <stdio.h>  /* printfcanf, NULL */
#include <stdlib.h> /* malloc, free, rand */

template<class TypeElems, class NodeType>
PointerList<TypeElems, NodeType>::PointerList(int numMaxElems) {
    Node<TypeElems>* nodeToInsert = new Node<TypeElems>();
    nodeToInsert->setNextPos(NULL);
    nodeToInsert->setPrevPos(NULL);
    _list = _tail = nodeToInsert;
    initialize(numMaxElems);
}

template<class TypeElems, class NodeType>
PointerList<TypeElems, NodeType>::PointerList(PointerList const &p) {

    Node<TypeElems>* nodeToInsert = new Node<TypeElems>();

    nodeToInsert->setNextPos(NULL);
    nodeToInsert->setPrevPos(NULL);
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

template<class TypeElems, class NodeType>
void PointerList<TypeElems, NodeType>::initialize(int maxElemsInside) {
    this->_elems_inside = 0;
    LinearList<TypeElems, PositionType>::initialize(maxElemsInside);
}

template<class TypeElems, class NodeType>
void PointerList<TypeElems, NodeType>::writeValueAt(PositionType p, TypeElems t) {
    p->setElem(t);
}

template<class TypeElems, class NodeType>
void PointerList<TypeElems, NodeType>::insertNodeAfter(PositionType p, TypeElems t) {

    Node<TypeElems>* nodeToInsert = new Node<TypeElems>(t);

    nodeToInsert->setNextPos(p->getNextPos());
    nodeToInsert->setPrevPos(p);
    if(isLastPosition(p)) _tail = nodeToInsert;
    p->setNextPos(nodeToInsert);
    this->setElementsInside(this->getElementsInside() + 1);
}

template<class TypeElems, class NodeType>
void PointerList<TypeElems, NodeType>::deleteNodeAt(PositionType p) {

    p->getPrevPos()->setNextPos(p->getNextPos());

    if(!isLastPosition(p))
        p->getNextPos()->setPrevPos(p->getPrevPos());
    else
        delete p;

    this->setElementsInside(this->getElementsInside() - 1);
}

template<class TypeElems, class NodeType>
TypeElems PointerList<TypeElems, NodeType>::readValueAt(PositionType p) const {
    return p->getElem();
}

template<class TypeElems, class NodeType>
bool PointerList<TypeElems, NodeType>::isEmpty() const {
    return _list->getNextPos() == NULL && _list->getPrevPos() == NULL;
}

template<class TypeElems, class NodeType>
bool PointerList<TypeElems, NodeType>::isLastPosition(PositionType p) const {
    return p->getNextPos() == NULL;
}

template<class TypeElems, class NodeType>
NodeType* PointerList<TypeElems, NodeType>::firstNodeList() const {
    return _list->getNextPos();
}

template<class TypeElems, class NodeType>
NodeType* PointerList<TypeElems, NodeType>::nextPosition(PositionType p) const {
    return p->getNextPos();
}

template<class TypeElems, class NodeType>
NodeType* PointerList<TypeElems, NodeType>::previousPosition(PositionType p) const {
    return p->getPrevPos();
}

template <class TypeElems,class NodeType>
PointerList<TypeElems, NodeType>::~PointerList() {
    // In a dynamic list with pointers, it's needed to deallocate all the
    // list memory cells, iterating through each
    delete _list;
}

template<class TypeElems, class NodeType>
bool PointerList<TypeElems, NodeType>::find(TypeElems elem) {
    bool found = false;
    if(!isEmpty())
      found = getFirstPositionByElem(elem) != NULL;

    return found;
}

/**
 * Can return NULL if the element is not found, or the position otherwise
 * @tparam T
 * @param t
 * @return
 */
template<class TypeElems, class NodeType>
NodeType* PointerList<TypeElems, NodeType>::getFirstPositionByElem(TypeElems t) {
    NodeType* head = _list;
    while (!isLastPosition(head)) {
        head = nextPosition(head);
        if(readValueAt(head) == t)
            return head;
    }
    return NULL;
}
