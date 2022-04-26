//
// Created by Greg on 21/04/22.
//

#include "../include/AdjacencyMatrixGraph.h"
#include <vector>

using std::vector;

template<class T, class WeightType>
void AdjacencyMatrixGraph<T, WeightType>::create() {
    
    adjacencyMatrix.push_back(new vector<WeightType>());
    *adjacencyMatrix.push_back(0);
}

template<class T, class WeightType>
bool AdjacencyMatrixGraph<T, WeightType>::isEmpty() {
    return false;
}

template<class T, class WeightType>
void AdjacencyMatrixGraph<T, WeightType>::insertNode(GraphNode<T> node) {
    assert(!nodesList.find(node));
    nodesList.insertNodeAfter(nodesList.lastNodeList(), node);
    int nNodes = Graph<T>::getNodesInside() + 1;
    Graph<T>::setNodesInside(nNodes);

    adjacencyMatrix.push_back(new vector<WeightType>(nNodes, NO_LINK)); // Add a new row with the new dim
    for (int i = 0; i < nNodes - 1; ++i)
        adjacencyMatrix[i].push_back(NO_LINK);// add element for each row

}

template<class T, class WeightType>
void AdjacencyMatrixGraph<T, WeightType>::insertLink(GraphNode<T> node1, GraphNode<T> node2) {
    Edge<T, WeightType> e(node1, node2);
    edgesList.insertNodeAfter(nodesList.lastNodeList(), e);

    node1.setLinks(node1.getLinks() + 1);
    node2.setLinks(node2.getLinks() + 1);

    auto row = adjacencyMatrix.at(node1);
    row.at(node2) = e.weight;
}

template<class T, class WeightType>
void AdjacencyMatrixGraph<T, WeightType>::removeNode(GraphNode<T> node) {
    assert(existsNode(node));
    assert(!node.hasLinks());

    auto pos = nodesList.getFirstPositionByElem(node.getElem());
    nodesList.deleteNodeAt(pos);
    Graph<T>::setNodesInside(Graph<T>::getNodesInside() - 1);

    std::remove(adjacencyMatrix.begin(), adjacencyMatrix.end(), node);

}

template<class T, class WeightType>
void AdjacencyMatrixGraph<T, WeightType>::removeLink(GraphNode<T> node1, GraphNode<T> node2) {

    assert(node1.getLinks() > 0);
    assert(node2.getLinks() > 0);
    assert(existsLink(node1, node2));



    node1.setLinks(node1.getLinks() - 1);
    node2.setLinks(node2.getLinks() - 1);
}

template<class T, class WeightType>
PointerList<GraphNode<T> *, 0> AdjacencyMatrixGraph<T, WeightType>::getAllNodes() {
    return nodesList;
}

template<class T, class WeightType>
PointerList<GraphNode<T>, 0> AdjacencyMatrixGraph<T, WeightType>::adjacents(GraphNode<T> node) {
    return PointerList<GraphNode<T>, 0>();
}

template<class T, class WeightType>
bool AdjacencyMatrixGraph<T, WeightType>::existsNode(GraphNode<T> node) {
    return nodesList.find(node);
}

template<class T, class WeightType>
bool AdjacencyMatrixGraph<T, WeightType>::existsLink(GraphNode<T> node, GraphNode<T> node1) {
    return ;
}

template<class T, class WeightType>
T AdjacencyMatrixGraph<T, WeightType>::readValue(GraphNode<T> node) {
    return nullptr;
}

template<class T, class WeightType>
void AdjacencyMatrixGraph<T, WeightType>::writeValue(GraphNode<T> node, T t) {

}
