//
// Created by Greg on 03/04/22.
//

#include "../../include/Queue.h"
#include "../include/PointerQueue.h"

template<class Type, int Size>
PointerQueue<Type, Size>::PointerQueue(){
    start = end = headQueue = nullptr;
    Queue<Type, Size>::create();
}

template<class Type, int Size>
bool PointerQueue<Type, Size>::isEmpty() {
    return start == end && this->elems_inside == 0;
}

template<class Type, int Size>
bool PointerQueue<Type, Size>::isFull() {
    return this->elems_inside == this->max_size;
}

template<class Type, int Size>
Type PointerQueue<Type, Size>::readQueue() {
    //TODO: verificare che la coda non sia vuota
    return headQueue->getElem();
}

template<class Type, int Size>
Type PointerQueue<Type, Size>::dequeue() {
    //TODO: Verificare che la coda non sia vuota
    Type temp_value = headQueue->getElem();
    TDA_Greg::Node<Type>* temp_node = headQueue;
    start = headQueue = headQueue->getNextPos();
    delete temp_node; // Non necessario perchè uscendo dalla funzione dealloca il nodo
    this->elems_inside--;
    return temp_value;
}

template<class Type, int Size>
void PointerQueue<Type, Size>::enqueue(Type elem) {
    //TODO verificare che la coda non sia piena
    auto nodeToEnqueue = new TDA_Greg::Node<Type>(elem);
    if(headQueue != nullptr) {
        position temp_pos = headQueue;
        while(!isLastNode(temp_pos)) temp_pos = temp_pos->getNextPos();
        temp_pos->setNextPos(nodeToEnqueue);

        // versione corretta
        // end->setNextPos(nodeToEnqueue);
    } else {
        start = headQueue = nodeToEnqueue;
    }
    nodeToEnqueue->setNextPos(nullptr);
    end = nodeToEnqueue;
    this->elems_inside ++;
}

template<class Type, int Size>
bool PointerQueue<Type, Size>::isLastNode(PointerQueue::position p) {
    return p->getNextPos() == nullptr;
}

template<class Type, int Size>
PointerQueue<Type, Size>::~PointerQueue() {
    while (!isEmpty())
        dequeue();
}

