//
// Created by Greg on 21/03/22.
//

#include "../include/LinkedList.h"
using namespace TDA_Greg;

template<class T>
void LinkedList<T>::initialize() {
    _head = new Node<T>();
    _head->setNextPos(_head);
    _head->setPrevPos(_head);
    this->_elems_inside = 0;
}

template<class T>
void LinkedList<T>::writeValueAt(Node<T> *p, const T t) {
    p->setElem(t);
}

template<class T>
void LinkedList<T>::insertNodeAfter(Node<T> *p, const T t) {
    Node<T>* nodeToInsert = new Node<T>(t);

    nodeToInsert->setNextPos(p->getNextPos());
    nodeToInsert->setPrevPos(p);
    p->setNextPos(nodeToInsert);
    this->setElementsInside(this->getElementsInside() + 1);
}

template<class T>
void LinkedList<T>::deleteNodeAt(const LinkedList::position p) {
    p->getPrevPos()->setNextPos(p->getNextPos());
    p->getNextPos()->setPrevPos(p->getPrevPos());
    delete p;
    this->setElementsInside(this->getElementsInside() - 1);
}

template<class T>
typename LinkedList<T>::type LinkedList<T>::readValueAt(LinkedList::position p) const {
    return p->getElem();
}

template<class T>
bool LinkedList<T>::isEmpty() const {
    return _head->getNextPos() == _head && _head->getPrevPos() == _head; // If the next position is equal to the same node (initialization cond.)
}

template<class T>
bool LinkedList<T>::isLastPosition(Node<T> *p) const {
    return p->getNextPos() == _head;
}

template<class T>
Node<T>* LinkedList<T>::firstNodeList() const {
    return _head->getNextPos();
}

template<class T>
Node<T>* LinkedList<T>::nextPosition(const LinkedList::position p) const {
    return p->getNextPos();
}

template<class T>
Node<T>* LinkedList<T>::previousPosition(const LinkedList::position p) const {
    return p->getPrevPos();
}

template<class T>
LinkedList<T>::~LinkedList() {
    delete _head;
}

template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &) {

}

template<class T>
bool LinkedList<T>::operator==(const LinkedList<T> &) {
    return false;
}

template<class T>
LinkedList<T>::LinkedList() {
    initialize();
}
