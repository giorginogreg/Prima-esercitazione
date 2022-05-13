//
// Created by Greg on 31/03/22.
//

#ifndef ESERCITAZIONI_ASD_QUEUE_VECTOR_H
#define ESERCITAZIONI_ASD_QUEUE_VECTOR_H
#include "../../include/Queue.h"

template<class Type>
class VectorQueue: public Queue<Type> {

public:
    VectorQueue(int);

    void create();
    virtual bool isEmpty();


    virtual Type readQueue();
    virtual Type dequeue();
    virtual void enqueue(Type);


private:

    Type* vectorQueue;
    int start;
    int end;

    void checkStartLimit();
    void checkEndLimit();
};

#include "../src/VectorQueue.tpp"

#endif //ESERCITAZIONI_ASD_QUEUE_VECTOR_H
