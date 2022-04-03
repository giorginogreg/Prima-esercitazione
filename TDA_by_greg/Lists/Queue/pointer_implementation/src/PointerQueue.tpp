//
// Created by Greg on 03/04/22.
//

#include "../../include/Queue.h"
#include "../include/PointerQueue.h"

template<class Type, int Size>
bool PointerQueue<Type, Size>::isEmpty() {
    return false;
}

template<class Type, int Size>
Type PointerQueue<Type, Size>::readQueue() {
    return 0;
}

template<class Type, int Size>
Type PointerQueue<Type, Size>::dequeue() {
    return 0;
}

template<class Type, int Size>
void PointerQueue<Type, Size>::enqueue(Type type) {

}

template<class Type, int Size>
void PointerQueue<Type, Size>::create() {
    Queue<Type, Size>::create();
}
