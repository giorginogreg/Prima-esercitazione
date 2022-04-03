//
// Created by Greg on 31/03/22.
//

#include "../include/VectorQueue.h"

#include <iostream>
#include <stdexcept>
template<class Type, int Size>
void VectorQueue<Type, Size>::create() {
    Queue<Type, Size>::create();
    start = 0, end = 0;
}

template<class Type, int Size>
bool VectorQueue<Type, Size>::isEmpty() {
    return start == end;
}

template<class Type, int Size>
Type VectorQueue<Type, Size>::readQueue() {
    return vectorQueue[start];
}

template<class Type, int Size>
Type VectorQueue<Type, Size>::dequeue() {
    try {
        checkLimits();
        return vectorQueue[start++];
    } catch (std::out_of_range &e) {
        std::cout << e.what() << std::endl;
    }
}

template<class Type, int Size>
void VectorQueue<Type, Size>::enqueue(Type el) {
    try {
        checkLimits();
        vectorQueue[end] = el;
        end += 1;
    } catch (std::out_of_range &e) {
        std::cout << e.what() << std::endl;
    }
}

template<class Type, int Size>
void VectorQueue<Type, Size>::checkLimits() {
    if(end + 1 > Queue<Type, Size>::max_size || start - 1 < 0 || start > end)
        throw std::out_of_range("You've reached the minimum/maximum elements that you can remove/add.");
}
