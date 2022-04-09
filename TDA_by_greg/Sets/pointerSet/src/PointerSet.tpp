//
// Created by Greg on 06/04/22.
//

#ifndef POINTERSET_POINTERSET_TPP
#define POINTERSET_POINTERSET_TPP

#include "../include/PointerSet.h"

using namespace std;

template<class T, int nElems>
void PointerSet<T, nElems>::create() {
    this->max_elems_inside = nElems;
}

template<class T, int nElems>
bool PointerSet<T, nElems>::isEmpty() {
    return p->isEmpty();
}

template<class T, int nElems>
void PointerSet<T, nElems>::insert(T t) {
    if(!belongsTo(t)) {
        p->insertNodeAfter(p->lastNodeList(), t);
    }
}

template<class T, int nElems>
bool PointerSet<T, nElems>::belongsTo(T t) {
    return p->find(t);
}

template<class T, int nElems>
Set <T, typename PointerSet<T, nElems>::PositionType>*
        PointerSet<T, nElems>::union_op( Set<T, PositionType>* set2 ) {
            // Trasformo un puntatore a set da Set a puntatore a un puntatore a PointerSet
            auto* pointerSet = dynamic_cast<PointerSet*>(set2);

            // alloco memoria con un costruttore di copia per la lista a puntatore del pointerSet
            auto unified_set = new PointerSet<T, nElems>();
            unified_set->p = new PointerList<T, nElems>(*(pointerSet->p));
            // Scandisco tutti gli elementi del secondo vettore
            auto temp_pos = p->getHead();

            if(!pointerSet->isEmpty()) {
                do {
                    temp_pos = temp_pos->getNextPos();
                    if(!pointerSet->belongsTo(temp_pos->getElem())) {
                        unified_set->insert(temp_pos->getElem());
                    }
                } while(!p->isLastPosition(temp_pos));
            }
            return unified_set;
}

template<class T, int nElems>
Set <T, typename PointerSet<T, nElems>::PositionType>*
    PointerSet<T, nElems>::intersect( Set<T, PositionType>* set2 ) {

    // Trasformo un puntatore a set da Set a puntatore a un puntatore a PointerSet
    auto* pointerSet = dynamic_cast<PointerSet*>(set2);

    // alloco memoria con un costruttore di copia per la lista a puntatore del pointerSet
    auto intersected_set = new PointerSet<T, nElems>();

    // Scandisco tutti gli elementi del secondo vettore
    auto temp_pos = p->getHead();

    if(!isEmpty()) {
        do {
            if(pointerSet->belongsTo(temp_pos->getElem())) {
                intersected_set->insert(temp_pos->getElem());
            }
            temp_pos = temp_pos->getNextPos();
        } while(!p->isLastPosition(temp_pos));
    }
    return intersected_set;
/*
    auto intersected_set = new PointerSet<T, nElems>();
    intersected_set.p = new PointerList<T, nElems>(set2.p);
    auto temp_pos = intersected_set.p->firstNodeList();
    while(!intersected_set.p->isLastPosition(temp_pos)){
        if(set2.find(temp_pos->getElem()))
            intersected_set->insertNodeAfter(intersected_set->lastNodeList(), temp_pos->getElem());
        temp_pos = temp_pos->getNextPos();
    }
    return intersected_set;*/
}

template<class T, int nElems>
Set <T, typename PointerSet<T, nElems>::PositionType>*
difference( PointerSet<T, nElems> set2 ) {
    auto diff_set = new PointerSet<T, nElems>();
    diff_set.p = new PointerList<T, nElems>(set2.p);

    auto temp_pos = set2.firstNodeList();
    while(!set2.isLastPosition(temp_pos)){
        if(set2.find(temp_pos->getElem()))
            diff_set.remove(temp_pos->getElem());
        temp_pos = temp_pos->getNextPos();
    }
    return diff_set;
}

template<class T, int nElems>
void PointerSet<T, nElems>::remove(T t) {
    p->deleteNodeAt(p->getFirstPositionByElem(t));
}

template<class T, int nElems>
ostream &PointerSet<T, nElems>::operator<<(ostream &o) {
    return o << endl;
}


#endif //POINTERSET_POINTERSET_TPP
