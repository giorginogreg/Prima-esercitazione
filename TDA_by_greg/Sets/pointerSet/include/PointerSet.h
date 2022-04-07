//
// Created by Greg on 06/04/22.
//

#ifndef POINTERQUEUE_POINTERSET_H
#define POINTERQUEUE_POINTERSET_H

#include <ostream>
#include "../../include/Set.h"

using namespace std;

template<class T, class PositionType>
class PointerSet: public Set<T, PositionType> {
public:
    void create();
    bool isEmpty();
    bool belongsTo(T t);
    void insert(T t);
    void remove(T t);
    Set<T, PositionType> union_op(Set<T, PositionType> set);
    Set<T, PositionType> intersect(Set<T, PositionType> set);
    Set<T, PositionType> difference(Set<T, PositionType> set);
    ostream &operator <<(ostream&);
protected:
    int elems_inside = 0;
};

#endif //POINTERQUEUE_POINTERSET_H
