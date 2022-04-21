//
// Created by Greg on 21/04/22.
//

#ifndef TDA_BINTREE_PRIORIQUEUE_H
#define TDA_BINTREE_PRIORIQUEUE_H

#include "../../include/Prioriqueue.h"

template<class T>
class BinTreePrioriqueue: public Prioriqueue<T>{
public:
    virtual void create();
    virtual void insert(T t);
    virtual T getMinimum();
    virtual void deleteMinimum();
};

#include "../src/BinTreePrioriqueue.tpp"

#endif //TDA_BINTREE_PRIORIQUEUE_H
