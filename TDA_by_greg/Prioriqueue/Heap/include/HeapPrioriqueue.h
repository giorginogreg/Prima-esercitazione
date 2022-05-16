//
// Created by Greg on 21/04/22.
//

#ifndef HEAP_HEAPPRIORIQUEUE_H
#define HEAP_HEAPPRIORIQUEUE_H

#include "../../include/Prioriqueue.h"

template<class T>
class HeapPrioriqueue: public Prioriqueue<T> {
public:

    HeapPrioriqueue(int);
    void create(int);
    void insert(T t);
    T getMinimum();
    void deleteMinimum();

    ~HeapPrioriqueue();


private:
    T* _heap;
    int _last_elem;

    void fixUp();
    void fixDown(int, int);

    void heapSort(int n);
};

#include "../src/HeapPrioriqueue.tpp"

#endif //HEAP_HEAPPRIORIQUEUE_H
