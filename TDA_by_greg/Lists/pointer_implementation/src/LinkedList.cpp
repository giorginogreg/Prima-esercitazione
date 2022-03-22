//
// Created by Greg on 21/03/22.
//

#include "../include/LinkedList.h"

template<class T, int S>
void LinkedList<T, S>::initialize() {
    _head = new TDA_Greg::Node<T>(0);
    _head->setNextPos(_head);
    _head->setPrevPos(_head);
}

template<class T, int S>
void LinkedList<T, S>::writeValueAt(TDA_Greg::Node<T> *p, T t) {
    p->setElem(t);
}

template<class T, int S>
void LinkedList<T, S>::insertNodeAfter(TDA_Greg::Node<T> *p, T t) {
    auto nodeToInsert = new TDA_Greg::Node<T>(t);

    if(isLastValue(p->getNextPos()))
        nodeToInsert->setNextPos(_head);
    else
        nodeToInsert->setNextPos(p->getPrevPos());
    p->setNextPos(nodeToInsert);
    nodeToInsert->setPrevPos(p);
}

template<class T, int S>
void LinkedList<T, S>::deleteNodeAt(TDA_Greg::Node<T> *p) {
    p->getPrevPos()->setNextPos(p->getNextPos());
    p->getNextPos()->setPrevPos(p->getPrevPos());
    delete p;
}

template<class T, int S>
T LinkedList<T, S>::readValueAt(TDA_Greg::Node<T> *p) {
    return p->getElem();
}

template<class T, int S>
bool LinkedList<T, S>::isEmpty() {
    return _head->getNextPos() == _head; // If the next position is equal to the same node (initialization cond.)
}

template<class T, int S>
bool LinkedList<T, S>::isLastValue(TDA_Greg::Node<T> *p) {
    return p == _head;
}

template<class T, int S>
TDA_Greg::Node<T>* LinkedList<T, S>::firstNodeList() {
    return _head;
}

template<class T, int S>
TDA_Greg::Node<T>* LinkedList<T, S>::nextPosition(TDA_Greg::Node<T> *p) {
    return p->getNextPos();
}

template<class T, int S>
TDA_Greg::Node<T>* LinkedList<T, S>::previousPosition(TDA_Greg::Node<T> *p) {
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
