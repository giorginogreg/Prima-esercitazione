
#ifndef POINTER_LIST_H
#define POINTER_LIST_H

#include "../../../../include/Node.h"
#include "../../Linear List/LinearList.h"

using TDA_Greg::Node;

// Insieme di nodi
template <class T, class NodeType = Node<T> >
class PointerList: public LinearList<T, NodeType*>
{

public:
     typedef NodeType* PositionType;

     PointerList(int); // Default constructor - Equal to create operator
     PointerList(const PointerList<T, NodeType> &Fp); // Copy constructor

     void writeValueAt(PositionType, T);
     void insertNodeAfter(PositionType, T);
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
    NodeType* _list;
    NodeType* _tail;

    void initialize(int);
};

#include "../src/PointerList.tpp"

#endif