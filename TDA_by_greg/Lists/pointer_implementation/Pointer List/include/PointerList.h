
#ifndef POINTER_LIST_H
#define POINTER_LIST_H

#include "../../../../include/Node.h"
#include "../../Linear List/LinearList.h"

using TDA_Greg::Node;

// Insieme di nodi
template <class T, int S>
class PointerList: public LinearList<T, Node<T>*, S>
{

public:
     typedef Node<T>* PositionType;

     PointerList(); // Default constructor - Equal to create operator
     PointerList(const PointerList<T,S> &Fp); // Copy constructor

     void initialize();

     void writeValueAt(PositionType i, T t);
     void insertNodeAfter(PositionType p, T t);
     void deleteNodeAt(PositionType p);
     T readValueAt(PositionType p) const;

     bool isEmpty() const;
     bool isLastPosition(PositionType p) const;
     PositionType firstNodeList() const;
     PositionType nextPosition(PositionType p) const;
     PositionType previousPosition(PositionType p) const;

     // Utility methods
     bool find(T);
     PositionType lastNodeList() { return _tail; };
     PositionType getFirstPositionByElem(T t); // Assuming that the elem exists in the list
     PositionType getHead() const { return _list; };
     // Destructor
     ~PointerList();

private:
    PositionType _list;
    PositionType _tail;
    int _max_nodes;

};

#include "../src/PointerList.tpp"

#endif