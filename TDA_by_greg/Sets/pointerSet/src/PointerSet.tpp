//
// Created by Greg on 06/04/22.
//

#ifndef POINTERSET_POINTERSET_TPP
#define POINTERSET_POINTERSET_TPP

#include "../include/PointerSet.h"

using namespace std;

template<class T, class NodeType>
void PointerSet<T, NodeType>::create(int nElems) {
    this->max_elems_inside = nElems;
    p = new PointerList<T>(nElems);
}

template<class T, class NodeType>
bool PointerSet<T, NodeType>::isEmpty() {
    return p->isEmpty();
}

template<class T, class NodeType>
void PointerSet<T, NodeType>::insert(T t) {
    if(!belongsTo(t)) {
        p->insertNodeAfter(p->lastNodeList(), t);
        Set<T, PositionType>::elems_inside++;
    }
}

template<class T, class NodeType>
bool PointerSet<T, NodeType>::belongsTo(T t) {
    return p->find(t);
}

template<class T, class NodeType>
Set <T, typename PointerSet<T, NodeType>::PositionType>*
        PointerSet<T, NodeType>::union_op( Set<T, PositionType>* set2 ) {
            // Trasformo un puntatore a set da Set a puntatore a un puntatore a PointerSet
            PointerSet<T, NodeType>* pointerSet = dynamic_cast<PointerSet*>(set2);

            // alloco memoria con un costruttore di copia per la lista a puntatore del pointerSet
            PointerSet<T, NodeType>* unified_set = new PointerSet<T, NodeType>();
            unified_set->p = new PointerList<T>(*(pointerSet->p));
            // Scandisco tutti gli elementi del secondo vettore
            NodeType* temp_pos = p->getHead();

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

template<class T, class NodeType>
Set <T, typename PointerSet<T, NodeType>::PositionType>*
    PointerSet<T, NodeType>::intersect( Set<T, PositionType>* set2 ) {

    // Trasformo un puntatore a set da Set a puntatore a un puntatore a PointerSet
    PointerSet<T, NodeType>* pointerSet = dynamic_cast<PointerSet*>(set2);

    // alloco memoria con un costruttore di copia per la lista a puntatore del pointerSet
    PointerSet<T, NodeType>* intersected_set = new PointerSet<T, NodeType>();

    // Scandisco tutti gli elementi del secondo vettore
    NodeType* temp_pos = p->getHead();

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
    auto intersected_set = new PointerSet<T, NodeType>();
    intersected_set.p = new PointerList<T, NodeType>(set2.p);
    auto temp_pos = intersected_set.p->firstNodeList();
    while(!intersected_set.p->isLastPosition(temp_pos)){
        if(set2.find(temp_pos->getElem()))
            intersected_set->insertNodeAfter(intersected_set->lastNodeList(), temp_pos->getElem());
        temp_pos = temp_pos->getNextPos();
    }
    return intersected_set;*/
}


template<class T, class NodeType>
Set<T, typename PointerSet<T, NodeType>::PositionType>
    *PointerSet<T, NodeType>::difference(Set<T, PositionType> *set) {
    PointerSet<T, NodeType>* pointerSet = dynamic_cast<PointerSet*>(set);
    PointerList<T, NodeType>* pointerList = pointerSet->p;
    PointerSet<T, NodeType>* diff_set = new PointerSet<T, NodeType>();
    diff_set->p = new PointerList<T>(*this->p);

    NodeType* temp_pos = p->getHead();
    do {
        temp_pos = temp_pos->getNextPos();
        if(pointerList->find(temp_pos->getElem())) // if elem is set on the other list..
            diff_set->remove(temp_pos->getElem());
    } while (!pointerList->isLastPosition(temp_pos));

    return diff_set;
}

template<class T, class NodeType>
void PointerSet<T, NodeType>::remove(T t) {
    p->deleteNodeAt(p->getFirstPositionByElem(t));
    Set<T, PositionType>::elems_inside--;
}

template<class T, class NodeType>
void PointerSet<T, NodeType>::printTDA() {
    NodeType* head = p->getHead();
    do {
        head = head->getNextPos();
        cout << head->getElem() << " | ";
    } while (!p->isLastPosition(head));
    cout << endl;
}

template<class T, class NodeType>
typename PointerSet<T, NodeType>::PositionType PointerSet<T, NodeType>::find(T t) {
    return p->getFirstPositionByElem(t);
}


template<class T, class NodeType>
PointerList<T, NodeType> PointerSet<T, NodeType>::getAllElementsAsPointerList() {
    return *p;
}

template<class T, class NodeType>
vector< T > PointerSet<T, NodeType>::getAllElements() {
    vector<T, NodeType>* pointerNodes = new vector<T, NodeType>();
    NodeType* head = p->getHead();
    do {
        head = head->getNextPos();
        pointerNodes->push_back(head->getElem());
    } while (!p->isLastPosition(head));
    return *pointerNodes;
}

template<class T, class NodeType>
ostream &operator<<(ostream &o, PointerSet<T, NodeType> &pointerSet) {

    o << "List Content: " << endl;
    pointerSet.printTDA();
    return o;

}

#endif //POINTERSET_POINTERSET_TPP
