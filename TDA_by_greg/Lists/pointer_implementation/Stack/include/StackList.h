//
// Created by Greg on 22/03/22.
//

#ifndef ALGORITHM_DATA_STRUCTURES_STACKLIST_H
#define ALGORITHM_DATA_STRUCTURES_STACKLIST_H

#include "../../Linear List/LinearList.h"
#include "../../Linked List/include/LinkedList.h"
#include "../../../../include/Node.h"

template<class T>
class StackList {

public:
    void push(T);
    T pop(); // Discard last changes
    bool empty();
    T top(); // Return last inserted element

private:
    LinkedList<T> _l;
    TDA_Greg::Node<T>* getLastNode();
};

#include "../src/StackList.tpp"

#endif //ALGORITHM_DATA_STRUCTURES_STACKLIST_H
