//
// Created by Greg on 22/03/22.
//

#ifndef ALGORITHM_DATA_STRUCTURES_STACKLIST_H
#define ALGORITHM_DATA_STRUCTURES_STACKLIST_H

#include "../../include/LinearList.h"
#include "Node.h"
template<class T, int S>
class StackList: public LinearList<T, TDA_Greg::Node<T> *, S> {

    void push();
    void pop(); // Discard last changes
    bool empty();
    T top(); // Return last inserted element

};

#endif //ALGORITHM_DATA_STRUCTURES_STACKLIST_H
