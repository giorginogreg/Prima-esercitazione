
#ifndef POINTER_LIST_H
#define POINTER_LIST_H

#include "../include/Node.h"
#include "../../include/LinearList.h"

using namespace TDA_Greg;

// Insieme di nodi
template <class T, class P, int S>
class PointerList: public LinearList<T, P, S>
{
public:
    virtual void initialize();

    virtual void writeValueAt(int i, T t);
    virtual void insertNodeAfter(P p, T t);
    virtual void deleteNodeAt(P p);
    virtual T readValueAt(P p);

    virtual bool isEmpty();
    virtual bool isLastValue(P p);
    virtual P firstNodeList();
    virtual P nextPosition(P p);
    virtual P previousPosition(P p);

    PointerList(); // Default constructor - Equal to create operator
    PointerList(int numElem);

    ~PointerList();

private:
    Node<T> *lista;
    int node_numbers = S;
    int elem_numbers; // No. of elems inside the list (useful to track how many elems are inside)

};


#endif