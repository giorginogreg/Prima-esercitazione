//
// Created by Greg on 21/04/22.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include "../../include/Node.h"
#include "../../Lists/pointer_implementation/Pointer List/include/PointerList.h"

using TDA_Greg::Node;

template<class T>
class Graph {
    virtual void create() = 0;
    virtual bool isEmpty() = 0;

    virtual void insertNode(Node<T>) = 0;
    virtual void insertLink(Node<T>, Node<T>) = 0;

    virtual void removeNode(Node<T>) = 0;
    virtual void removeLink(Node<T>, Node<T>) = 0;

    virtual PointerList<Node<T>,0> adjacents(Node<T>) = 0;
    virtual bool existsNode(Node<T>) = 0;
    virtual bool existsLink(Node<T>, Node<T>) = 0;

    virtual T readValue(Node<T>) = 0;
    virtual void writeValue(Node<T>, T) = 0;



};

#endif //GRAPHS_GRAPH_H
