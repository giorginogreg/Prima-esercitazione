//
// Created by Greg on 03/04/22.
//

//#include "../../include/Queue.h"
#include "../include/Queue.h"
#include "../include/PointerQueue.h"
#include "assert.h"

using namespace TDA_Greg;

template<class Type>
PointerQueue<Type>::PointerQueue(int maxElemsInside){
    start = end = headQueue = NULL;
    Queue<Type>::create(maxElemsInside);
}

template<class Type>
bool PointerQueue<Type>::isEmpty() {
    return start == end && this->elems_inside == 0;
}

template<class Type>
bool PointerQueue<Type>::isFull() {
    return this->elems_inside == this->max_size;
}

template<class Type>
Type PointerQueue<Type>::readQueue() {
    assert(!isEmpty());
    return headQueue->getElem();
}

template<class Type>
Type PointerQueue<Type>::dequeue() {
    assert(!isEmpty());
    Type temp_value = headQueue->getElem();
    Node<Type>* temp_node = headQueue;
    start = headQueue = headQueue->getNextPos();
    delete temp_node; // Non necessario perchè uscendo dalla funzione dealloca il nodo
    this->elems_inside--;
    return temp_value;
}

template<class Type>
void PointerQueue<Type>::enqueue(Type elem) {
    assert(!isFull());
    Node<Type>* nodeToEnqueue = new Node<Type>(elem);
    if(headQueue != NULL) {
        position temp_pos = headQueue;
        while(!isLastNode(temp_pos)) temp_pos = temp_pos->getNextPos();
        temp_pos->setNextPos(nodeToEnqueue);

        // versione corretta
        // end->setNextPos(nodeToEnqueue);
    } else {
        start = headQueue = nodeToEnqueue;
    }
    nodeToEnqueue->setNextPos(NULL);
    end = nodeToEnqueue;
    this->elems_inside ++;
}

template<class Type>
bool PointerQueue<Type>::isLastNode(PointerQueue::position p) {
    return p->getNextPos() == NULL;
}

template<class Type>
PointerQueue<Type>::~PointerQueue() {
    while (!isEmpty())
        dequeue();
}

