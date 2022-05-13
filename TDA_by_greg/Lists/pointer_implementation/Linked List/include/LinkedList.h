//
// Created by Greg on 21/03/22.
//

#ifndef ALGORITHM_DATA_STRUCTURES_LINKEDLIST_H
#define ALGORITHM_DATA_STRUCTURES_LINKEDLIST_H

#include "../../Linear List/LinearList.h"
#include "../../../../include/Node.h"

template<class T>
class LinkedList: public LinearList<T, TDA_Greg::Node<T>*>{

public:
    LinkedList();

    //Utility
    typedef T type;
    typedef TDA_Greg::Node<T>* position;

    void initialize();
    void writeValueAt(position p, T);
    void insertNodeAfter(position p, T);
    void deleteNodeAt(position p);
    type readValueAt(position p) const;

    bool isEmpty() const;
    bool isLastPosition(position p) const;
    position firstNodeList() const;
    position nextPosition(position p) const;
    position previousPosition(position p) const;

    virtual ~LinkedList();

    LinkedList& operator =(const LinkedList<T> &);
    bool operator ==(const LinkedList<T> &);

private:
    position _head;

};

#include "../src/LinkedList.tpp"

#endif //ALGORITHM_DATA_STRUCTURES_LINKEDLIST_H
