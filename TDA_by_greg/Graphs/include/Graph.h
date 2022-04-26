//
// Created by Greg on 21/04/22.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include "../../include/GraphNode.h"
#include "../../Lists/pointer_implementation/Pointer List/include/PointerList.h"

using TDA_Greg::Node;

template<class T>
class Graph {
    virtual void create() = 0;
    virtual bool isEmpty() = 0;

    virtual void insertNode(GraphNode<T>) = 0;
    virtual void insertLink(GraphNode<T>, GraphNode<T>) = 0;

    virtual void removeNode(GraphNode<T>) = 0;
    virtual void removeLink(GraphNode<T>, GraphNode<T>) = 0;

    virtual PointerList<GraphNode<T>*, 0> getAllNodes() = 0;
    virtual PointerList<GraphNode<T>,0> adjacents(GraphNode<T>) = 0;
    virtual bool existsNode(GraphNode<T>) = 0;
    virtual bool existsLink(GraphNode<T>, GraphNode<T>) = 0;

    virtual T readValue(GraphNode<T>) = 0;
    virtual void writeValue(GraphNode<T>, T) = 0;

    // For tree-weight we need also the info of the value in the link
    int getNodesInside() { return _nodesInside; }
    void setNodesInside(int n) { _nodesInside = n; }

private:
    // ArcsList
    // NodesList
    int _nodesInside;
};

#endif //GRAPHS_GRAPH_H
