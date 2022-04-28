//
// Created by Greg on 06/04/22.
//

#ifndef POINTERQUEUE_POINTERSET_H
#define POINTERQUEUE_POINTERSET_H

#include <ostream>
#include "../../include/Set.h"
#include "../../../include/Node.h"
#include "../../../Lists/pointer_implementation/Pointer List/include/PointerList.h"

using namespace std;

template<class T, int elems>
class PointerSet: public Set<T, TDA_Greg::Node<T>* > {
public:
    typedef TDA_Greg::Node<T>* PositionType;

    PointerSet(){
        this->elems_inside = 0;
        create();
    }

    ~PointerSet() { delete p; }

    void create();
    bool isEmpty();
    bool belongsTo(T t);

    T find(T t);
    vector<T> getAllElements();

    void insert(T t);
    void remove(T t);
    Set<T, PositionType>* union_op(Set<T, PositionType>* set);
    Set<T, PositionType>* intersect(Set<T, PositionType>* set);
    Set<T, PositionType>* difference( Set<T, PositionType>* set);
    void printTDA();

protected:
    PointerList<T, elems>* p = new PointerList<T, elems>();
};

#include "../src/PointerSet.tpp"

#endif //POINTERQUEUE_POINTERSET_H
