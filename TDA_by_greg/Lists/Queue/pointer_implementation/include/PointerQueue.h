//
// Created by Greg on 03/04/22.
//

#ifndef POINTERQUEUE_H
#define POINTERQUEUE_H
#include "../../include/Queue.h"

template<class Type, int Size>
class PointerQueue: public Queue<Type, Size> {
public:
    virtual bool isEmpty();
    virtual Type readQueue();
    virtual Type dequeue();
    virtual void enqueue(Type type);
    void create() override;
};

#include "../src/PointerQueue.tpp"

#endif //POINTERQUEUE_H
