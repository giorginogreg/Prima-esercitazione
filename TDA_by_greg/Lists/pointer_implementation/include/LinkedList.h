//
// Created by Greg on 21/03/22.
//

#ifndef ALGORITHM_DATA_STRUCTURES_LINKEDLIST_H
#define ALGORITHM_DATA_STRUCTURES_LINKEDLIST_H

#include "../../include/LinearList.h"
#include "Node.h"

template<class T, int S>
class LinkedList: public LinearList<T, TDA_Greg::Node<T>*, S>{

public:
    
    //Utility
    //typedef typename LinearList<T, TDA_Greg::Node<T> *, S>::type TDA_Greg::Node<T> *t;
    //typedef typename LinearList<T, TDA_Greg::Node<T> *, S>::position position;

    virtual void initialize();
    virtual void writeValueAt(TDA_Greg::Node<T> *p, T);
    virtual void insertNodeAfter(TDA_Greg::Node<T> *p, T);
    virtual void deleteNodeAt(TDA_Greg::Node<T> *p);

    virtual T readValueAt(TDA_Greg::Node<T> *p);
    virtual bool isEmpty();
    virtual bool isLastValue(TDA_Greg::Node<T> *p);
    virtual TDA_Greg::Node<T> *firstNodeList();
    virtual TDA_Greg::Node<T> *nextPosition(TDA_Greg::Node<T> *p);
    virtual TDA_Greg::Node<T> *previousPosition(TDA_Greg::Node<T> *p);

    virtual ~LinkedList();

    LinkedList& operator =(const LinkedList<T, S> &);
    bool operator ==(const LinkedList<T, S> &);

private:
    TDA_Greg::Node<T> *_head;

};

#endif //ALGORITHM_DATA_STRUCTURES_LINKEDLIST_H
