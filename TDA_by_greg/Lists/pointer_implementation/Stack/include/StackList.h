//
// Created by Greg on 22/03/22.
//

#ifndef ALGORITHM_DATA_STRUCTURES_STACKLIST_H
#define ALGORITHM_DATA_STRUCTURES_STACKLIST_H

#include "../../include/LinearList.h"
#include "../include/LinkedList.h"
#include "../src/LinkedList.cpp"
#include "Node.h"
template<class T, int S>
class StackList {

public:
    virtual void push(T);
    virtual T pop(); // Discard last changes
    virtual bool empty();
    virtual T top(); // Return last inserted element

private:
    LinkedList<T, S> _l;
    TDA_Greg::Node<T>* getLastNode();
};

template<class T, int S>
void StackList<T, S>::push(T elem) {
    auto last_node = getLastNode();
    _l.insertNodeAfter(last_node, elem);
}

template<class T, int S>
TDA_Greg::Node<T>* StackList<T, S>::getLastNode() {
    auto first_node = _l.firstNodeList();
    while(!_l.isLastPosition(first_node))
        first_node = first_node->getNextPos();
    return first_node;
}

template<class T, int S>
T StackList<T, S>::pop() {
    auto last_node = getLastNode();
    T temp_value = last_node->getElem();
    _l.deleteNodeAt(last_node);
    return temp_value;
}

template<class T, int S>
bool StackList<T, S>::empty() {
    return _l.isEmpty();
}

template<class T, int S>
T StackList<T, S>::top() {
    return getLastNode()->getElem();
}


#endif //ALGORITHM_DATA_STRUCTURES_STACKLIST_H
