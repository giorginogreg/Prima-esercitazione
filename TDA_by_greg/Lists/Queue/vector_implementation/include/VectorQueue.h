//
// Created by Greg on 31/03/22.
//
#include "../../include/Queue.h"

#ifndef ESERCITAZIONI_ASD_QUEUE_VECTOR_H
#define ESERCITAZIONI_ASD_QUEUE_VECTOR_H

template<class Type, int Size>
class VectorQueue: public Queue<Type, Size> {
public:
    virtual void create();
    virtual bool isEmpty();
    virtual Type readQueue();
    virtual Type dequeue();
    virtual void enqueue(Type type);
private:
    Type vectorQueue[Size];
    int start;
    int end;

    void checkLimits();
};

#endif //ESERCITAZIONI_ASD_QUEUE_VECTOR_H
