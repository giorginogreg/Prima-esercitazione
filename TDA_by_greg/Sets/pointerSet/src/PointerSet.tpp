//
// Created by Greg on 06/04/22.
//

#ifndef POINTERSET_POINTERSET_TPP
#define POINTERSET_POINTERSET_TPP

#include "../include/PointerSet.h"

using namespace std;

template<class T, class PositionType>
void PointerSet<T, PositionType>::create() {

}

template<class T, class PositionType>
bool PointerSet<T, PositionType>::isEmpty() {
    return false;
}

template<class T, class PositionType>
bool PointerSet<T, PositionType>::belongsTo(T t) {
    return false;
}

template<class T, class PositionType>
void PointerSet<T, PositionType>::insert(T t) {

}

template<class T, class PositionType>
Set<T, PositionType> PointerSet<T, PositionType>::union_op(Set<T, PositionType> set) {
    return Set<T, PositionType>();
}

template<class T, class PositionType>
Set<T, PositionType> PointerSet<T, PositionType>::intersect(Set<T, PositionType> set) {
    return Set<T, PositionType>();
}

template<class T, class PositionType>
Set<T, PositionType> PointerSet<T, PositionType>::difference(Set<T, PositionType> set) {
    return Set<T, PositionType>();
}

template<class T, class PositionType>
void PointerSet<T, PositionType>::remove(T t) {

}

template<class T, class PositionType>
ostream &PointerSet<T, PositionType>::operator<<(ostream &o) {
    return o << endl;
}






#endif //POINTERSET_POINTERSET_TPP
