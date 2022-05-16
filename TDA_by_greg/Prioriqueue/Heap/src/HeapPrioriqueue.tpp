//
// Created by Greg on 21/04/22.
//

#ifndef HEAP_HEAPPRIORIQUEUE_TPP
#define HEAP_HEAPPRIORIQUEUE_TPP

#include <cstdio>
#include <cassert>
#include "../include/HeapPrioriqueue.h"

template<class T>
HeapPrioriqueue<T>::HeapPrioriqueue(const int max_length){
    _heap = new T[max_length];
    create(max_length);
}

template<class T>
void HeapPrioriqueue<T>::create(const int max_length) {
    _last_elem = 0;
    Prioriqueue<T>::max_elems_inside = max_length;
}

template<class T>
void HeapPrioriqueue<T>::insert(T t) {
    assert(_last_elem < this->max_elems_inside);
    _heap[++_last_elem - 1] = t;
    fixUp();
}

template<class T>
T HeapPrioriqueue<T>::getMinimum() {
    assert(_last_elem > 0);
    return _heap[0];
}

template<class T>
void HeapPrioriqueue<T>::deleteMinimum() {
    assert(_last_elem > 0);
     _heap[0] = _heap[_last_elem - 1];
     _last_elem--;
    fixDown(1, _last_elem);
}


template<class T>
HeapPrioriqueue<T>::~HeapPrioriqueue() {
    delete[] _heap;
}

template<class T>
void HeapPrioriqueue<T>::fixUp() {
    int k = _last_elem;

    while (k > 1 && _heap[k-1] < _heap[k / 2 - 1]) { // if node is less than ancestor swap
        T tmp = _heap[k-1];
        _heap[k-1] = _heap[ k/2 - 1];
        _heap[ k/2 - 1] = tmp;
        k /= 2;
    }
}

template<class T>
void HeapPrioriqueue<T>::fixDown(int k, int N) {
    int scambio = 1;
    while(k <= N / 2 && scambio) {
        int j = k*2;
        if (j > N && _heap[j - 1] > _heap[j]) { // if left son is greater than right son
            j++; // Switch to the next son
        }
        scambio = _heap[j - 1] < _heap[k - 1];
        if(scambio) {
            T tmp = _heap[k-1];
            _heap[k-1] = _heap[ j - 1];
            _heap[ j - 1] = tmp;
            k = j;
        }
    }
}

template<class T>
void HeapPrioriqueue<T>::heapSort(int n) {
    for(int i = 0; i < n; i++){
        fixUp(i);
    }
    for(int i = 0; i < n; i++){
        swap(_heap, 0, n-i);
        fixDown(1, n-1-i);
    }
}

#endif //HEAP_HEAPPRIORIQUEUE_TPP
