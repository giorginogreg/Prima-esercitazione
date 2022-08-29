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
#include "../../../Sets/pointerSet/include/PointerSet.h"
#include <vector>
using std::vector;

#define NO_LINK 0
#define DEFAULT_LINK 1
template<class T, class WeightType>
class AdjacencyMatrixGraph : public Graph<T, WeightType> {
public:
    AdjacencyMatrixGraph();
    ~AdjacencyMatrixGraph();

    void create();
    bool isEmpty();
    
    void insertNode(GraphNode<T>* node);
    void removeNode(GraphNode<T>* node);

    void insertLink(GraphNode<T>*, GraphNode<T>*, WeightType w = DEFAULT_LINK);
    void removeLink(GraphNode<T>*, GraphNode<T>*);
    WeightType getLinkWeight(GraphNode<T>, GraphNode<T>);

    PointerList<GraphNode<T>> getAllNodes();
    PointerList<GraphNode<T>> adjacents(GraphNode<T> node);
    bool existsNode(GraphNode<T> node);
    bool existsLink(GraphNode<T> node, GraphNode<T> node2);

    T readValue(GraphNode<T> node);
    void writeValue(GraphNode<T>* node, T t);

private:
    void setWeight(GraphNode<T> node1, GraphNode<T> node2, WeightType w);

    PointerList<Edge<T, WeightType> >* edgesList;
    PointerSet<T, GraphNode<T> >* nodesList; // Lista di nodi di tipo T

    vector< vector<WeightType> > adjacencyMatrix;
};

#include "./../src/AdjacencyMatrixGraph.tpp"

#endif