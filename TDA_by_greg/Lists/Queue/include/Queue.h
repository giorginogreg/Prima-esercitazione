//
// Created by Greg on 31/03/22.
//

#ifndef ESERCITAZIONI_ASD_TAIL_H
#define ESERCITAZIONI_ASD_TAIL_H

template<class Type, int Size>
class Queue {

public:
    virtual void create();
    virtual bool isEmpty() = 0;
    virtual Type readQueue() = 0;
    virtual Type dequeue() = 0;
    virtual void enqueue(Type) = 0;

//private:
    // implementation dependant
protected:
    int elems_inside = 0;
    int max_size = 0;
};

#include "../src/Queue.tpp"

#endif //ESERCITAZIONI_ASD_TAIL_H
