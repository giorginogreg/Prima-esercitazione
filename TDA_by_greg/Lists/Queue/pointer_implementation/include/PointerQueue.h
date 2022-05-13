//
// Created by Greg on 03/04/22.
//

#ifndef POINTERQUEUE_H
#define POINTERQUEUE_H
#include "../../include/Queue.h"
#include "../../../../include/Node.h"

template<class Type>
class PointerQueue: public Queue<Type> {

    typedef TDA_Greg::Node<Type>* position;

public:
    PointerQueue(int maxElemsInside);

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
