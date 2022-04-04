//
// Created by Greg on 03/04/22.
//

#ifndef POINTERQUEUE_H
#define POINTERQUEUE_H
#include "../../include/Queue.h"
#include "../../../pointer_implementation/include/Node.h"

template<class Type, int Size>
class PointerQueue: public Queue<Type, Size> {

    typedef TDA_Greg::Node<Type>* position;

public:
    PointerQueue();

    virtual ~PointerQueue();

    bool isEmpty();
    Type readQueue();
    Type dequeue();
    void enqueue(Type elem);

private:
    position headQueue;
    position start;
    position end;
    bool isLastNode(position);
    bool isFull();
};

#include "../src/PointerQueue.tpp"

#endif //POINTERQUEUE_H
