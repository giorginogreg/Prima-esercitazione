//
// Created by Greg on 21/04/22.
//

#ifndef HEAP_HEAPPRIORIQUEUE_H
#define HEAP_HEAPPRIORIQUEUE_H

#include "../../include/Prioriqueue.h"

template<class T>
class HeapPrioriqueue: public Prioriqueue<T> {
public:
    virtual void create();
    virtual void insert(T t);
    virtual T getMinimum();
    virtual void deleteMinimum();
};

#include "../src/HeapPrioriqueue.tpp"

#endif //HEAP_HEAPPRIORIQUEUE_H
