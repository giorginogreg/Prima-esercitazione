//
// Created by Greg on 31/03/22.
//

#include "../include/VectorQueue.h"

#include <iostream>
#include <stdexcept>

#define INITIAL_INDEX -1

template<class Type>
VectorQueue<Type>::VectorQueue(int maxElemsInside) {
    vectorQueue = new Type[maxElemsInside];
    Queue<Type>::create(maxElemsInside);
    create();
}

template<class Type>
void VectorQueue<Type>::create() {
    start = INITIAL_INDEX, end = INITIAL_INDEX;
}

template<class Type>
bool VectorQueue<Type>::isEmpty() {
    return start == INITIAL_INDEX && end == INITIAL_INDEX;
}

template<class Type>
Type VectorQueue<Type>::readQueue() {
    return vectorQueue[start];
}

template<class Type>
Type VectorQueue<Type>::dequeue() {
    //try {
        checkStartLimit();
        start += 1;
        return vectorQueue[start];
    //} catch (std::out_of_range &e) {
    //    std::cout << e.what() << std::endl;
    //}
    return INT32_MIN;
}

template<class Type>
void VectorQueue<Type>::enqueue(Type el) {
    //try {
        checkEndLimit();
        if(start == INITIAL_INDEX)
            start += 1;
        end += 1;
        vectorQueue[end] = el;
    //} catch (std::out_of_range &e) {
      //  std::cout << e.what() << std::endl;
    //}
}

template<class Type>
void VectorQueue<Type>::checkEndLimit() {
    if(
        end + 1 > Queue<Type>::max_size // Condition for enqueue
    )
        throw std::out_of_range("You've reached the minimum/maximum elements that you can remove/add.");
}

template<class Type>
void VectorQueue<Type>::checkStartLimit() {
    if( start - 1 < INITIAL_INDEX || start > end )
        throw std::out_of_range("You've reached the minimum/maximum elements that you can remove/add.");
}

