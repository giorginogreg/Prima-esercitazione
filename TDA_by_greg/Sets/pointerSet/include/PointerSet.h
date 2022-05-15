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

template<class T, class NodeType = Node<T>>
class PointerSet: public Set<T, NodeType* > {
public:
    typedef NodeType* PositionType;

    PointerSet(int maxElemsInside = 10){
        this->elems_inside = 0;
        create(maxElemsInside);
    }

    ~PointerSet() { delete p; }

    void create(int);
    bool isEmpty();
    bool belongsTo(T t);

    PositionType find(T t);
    PointerList<T> getAllElementsAsPointerList();
    vector<T> getAllElements();

    void insert(T t);
    void remove(T t);
    Set<T, PositionType>* union_op(Set<T, PositionType>* set);
    Set<T, PositionType>* intersect(Set<T, PositionType>* set);
    Set<T, PositionType>* difference( Set<T, PositionType>* set);
    void printTDA();

protected:
    PointerList<T>* p;
};

#include "../src/PointerSet.tpp"

#endif //POINTERQUEUE_POINTERSET_H
