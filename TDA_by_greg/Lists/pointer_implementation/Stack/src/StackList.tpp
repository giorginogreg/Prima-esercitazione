//
// Created by Greg on 22/03/22.
//

#include "../include/StackList.h"

template<class T>
void StackList<T>::push(T elem) {
    auto last_node = getLastNode();
    _l.insertNodeAfter(last_node, elem);
}

template<class T>
TDA_Greg::Node<T>* StackList<T>::getLastNode() {
    auto first_node = _l.firstNodeList();
    while(!_l.isLastPosition(first_node))
        first_node = first_node->getNextPos();
    return first_node;
}

template<class T>
T StackList<T>::pop() {
    assert(!empty());
    auto last_node = getLastNode();
    T temp_value = last_node->getElem();
    _l.deleteNodeAt(last_node);
    return temp_value;
}

template<class T>
bool StackList<T>::empty() {
    return _l.isEmpty();
}

template<class T>
T StackList<T>::top() {
    return getLastNode()->getElem();
}

