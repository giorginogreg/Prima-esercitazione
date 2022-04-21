//
// Created by Greg on 21/04/22.
//

#ifndef HEAP_HEAPPRIORIQUEUE_TPP
#define HEAP_HEAPPRIORIQUEUE_TPP

#include <cstdio>
#include <cassert>
#include "../include/HeapPrioriqueue.h"

template<class T, int MAX_LENGTH>
HeapPrioriqueue<T, MAX_LENGTH>::HeapPrioriqueue(){
    _heap = new T[MAX_LENGTH];
    create();
}

template<class T, int MAX_LENGTH>
void HeapPrioriqueue<T,MAX_LENGTH>::create() {
    _last_elem = 0;
}

template<class T, int MAX_LENGTH>
void HeapPrioriqueue<T, MAX_LENGTH>::insert(T t) {
    assert(_last_elem < MAX_LENGTH);
    _heap[++_last_elem - 1] = t;
    fixUp();
}

template<class T, int MAX_LENGTH>
T HeapPrioriqueue<T, MAX_LENGTH>::getMinimum() {
    assert(_last_elem > 0);
    return _heap[0];
}

template<class T, int MAX_LENGTH>
void HeapPrioriqueue<T, MAX_LENGTH>::deleteMinimum() {
    assert(_last_elem > 0);
     _heap[0] = _heap[_last_elem - 1];
     _last_elem--;
    fixDown(1, _last_elem);
}


template<class T, int MAX_LENGTH>
HeapPrioriqueue<T, MAX_LENGTH>::~HeapPrioriqueue() {
    delete[] _heap;
}

template<class T, int MAX_LENGTH>
void HeapPrioriqueue<T, MAX_LENGTH>::fixUp() {
    int k = _last_elem;

    while (k > 1 && _heap[k-1] < _heap[k / 2 - 1]) { // if node is less than ancestor swap
        T tmp = _heap[k-1];
        _heap[k-1] = _heap[ k/2 - 1];
        _heap[ k/2 - 1] = tmp;
        k /= 2;
    }
}

template<class T, int MAX_LENGTH>
void HeapPrioriqueue<T, MAX_LENGTH>::fixDown(int k, int N) {
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

#endif //HEAP_HEAPPRIORIQUEUE_TPP
