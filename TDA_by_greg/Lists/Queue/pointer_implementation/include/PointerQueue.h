//
// Created by Greg on 03/04/22.
//

#ifndef POINTERQUEUE_H
#define POINTERQUEUE_H
#include "../../include/Queue.h"

template<class Type, int Size>
class PointerQueue: public Queue<Type, Size> {
public:
    bool isEmpty();
    Type readQueue();
    Type dequeue();
    void enqueue(Type type);
    void create() override;
};

#include "../src/PointerQueue.tpp"

#endif //POINTERQUEUE_H
