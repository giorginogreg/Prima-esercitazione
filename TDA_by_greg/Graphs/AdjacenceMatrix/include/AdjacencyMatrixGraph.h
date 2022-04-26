//
// Created by Greg on 21/04/22.
//

// La matrice sarà un puntatore a elem di tipo InfoNodo

// Infonodo ha
//      etichetta
//      isEmpty: bool
//      info: *void
//      archi: *InfoArco<P> - Memorizzo archi uscenti dal nodo

// InfoArco
    // Peso
    // isEmpty

// Nodo
    // Ogni nodo ha un identificativo e relativi getter/setter
#ifndef ADJACENCY_MATRIX_GRAPH
#define ADJACENCY_MATRIX_GRAPH

#include "../../include/Graph.h"
#include "../../../include/GraphNode.h"
#include "../../include/Link.h"
#include "../../../Lists/pointer_implementation/Pointer List/include/PointerList.h"
#include <vector>
using std::vector;

#define NO_LINK 0

template<class T, class WeightType>
class AdjacencyMatrixGraph : public Graph<T> {
public:
    void create();
    bool isEmpty();
    
    void insertNode(GraphNode<T> node);
    void removeNode(GraphNode<T> node);

    void insertLink(GraphNode<T>, GraphNode<T>);
    void removeLink(GraphNode<T>, GraphNode<T>);

    PointerList<GraphNode<T>*, 0> getAllNodes();
    PointerList<GraphNode<T>, 0> adjacents(GraphNode<T> node);
    bool existsNode(GraphNode<T> node);
    bool existsLink(GraphNode<T> node, GraphNode<T> node1);

    T readValue(GraphNode<T> node);
    void writeValue(GraphNode<T> node, T t);

private:
    PointerList<Edge<T, WeightType>, 0> edgesList;
    PointerList<GraphNode<T>, 0> nodesList;
    vector<vector<WeightType>> adjacencyMatrix;
};

#include "./../src/AdjacencyMatrixGraph.tpp"

#endif