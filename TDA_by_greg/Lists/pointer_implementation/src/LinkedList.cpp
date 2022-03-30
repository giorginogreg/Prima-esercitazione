//
// Created by Greg on 21/03/22.
//

#include "../include/LinkedList.h"

template<class T, int S>
void LinkedList<T, S>::initialize() {
    _head = new TDA_Greg::Node<T>();
    _head->setNextPos(_head);
    _head->setPrevPos(_head);
    this->_elems_inside = 0;
}

template<class T, int S>
void LinkedList<T, S>::writeValueAt(TDA_Greg::Node<T> *p, const T t) {
    p->setElem(t);
}

template<class T, int S>
void LinkedList<T, S>::insertNodeAfter(TDA_Greg::Node<T> *p, const T t) {
    auto nodeToInsert = new TDA_Greg::Node<T>(t);

    if(isLastPosition(p->getNextPos()))
        nodeToInsert->setNextPos(_head);
    else
        nodeToInsert->setNextPos(p->getPrevPos());
    p->setNextPos(nodeToInsert);
    nodeToInsert->setPrevPos(p);
    this->setElementsInside(this->getElementsInside() + 1);
}

template<class T, int S>
void LinkedList<T, S>::deleteNodeAt(const LinkedList::position p) {
    p->getPrevPos()->setNextPos(p->getNextPos());
    p->getNextPos()->setPrevPos(p->getPrevPos());
    delete p;
    this->setElementsInside(this->getElementsInside() - 1);
}

template<class T, int S>
typename LinkedList<T,S>::type LinkedList<T, S>::readValueAt(const LinkedList::position p) {
    return p->getElem();
}

template<class T, int S>
bool LinkedList<T, S>::isEmpty() {
    return _head->getNextPos() == _head; // If the next position is equal to the same node (initialization cond.)
}

template<class T, int S>
bool LinkedList<T, S>::isLastPosition(TDA_Greg::Node<T> *p) {
    return p->getNextPos() == _head;
}

template<class T, int S>
TDA_Greg::Node<T>* LinkedList<T, S>::firstNodeList() {
    return _head->getNextPos();
}

template<class T, int S>
TDA_Greg::Node<T>* LinkedList<T, S>::nextPosition(const LinkedList::position p) {
    return p->getNextPos();
}

template<class T, int S>
TDA_Greg::Node<T>* LinkedList<T, S>::previousPosition(const LinkedList::position p) {
    return p->getPrevPos();
}

template<class T, int S>
LinkedList<T, S>::~LinkedList() {
    delete _head;
}

template<class T, int S>
LinkedList<T, S> &LinkedList<T, S>::operator=(const LinkedList<T, S> &) {

}

template<class T, int S>
bool LinkedList<T, S>::operator==(const LinkedList<T, S> &) {
    return false;
}

template<class T, int S>
LinkedList<T, S>::LinkedList() {
    initialize();
}



