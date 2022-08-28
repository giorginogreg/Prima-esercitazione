//
// Created by Greg on 31/03/22.
//

#include "../include/Queue.h"

template<class Type>
void Queue<Type>::create(int maxElemsInside) {
    elems_inside = 0;
    max_size = maxElemsInside;
}
