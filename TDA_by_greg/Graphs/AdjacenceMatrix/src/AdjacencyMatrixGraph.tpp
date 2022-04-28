//
// Created by Greg on 21/04/22.
//

#include "../include/AdjacencyMatrixGraph.h"
#include <vector>

using std::vector;

template<class T, class WeightType>
AdjacencyMatrixGraph<T, WeightType>::AdjacencyMatrixGraph(){
    create();
}



template<class T, class WeightType>
void AdjacencyMatrixGraph<T, WeightType>::create() {

}



template<class T, class WeightType>
bool AdjacencyMatrixGraph<T, WeightType>::isEmpty() {
    return nodesList.getElemsInside() == 0;
}

template<class T, class WeightType>
void AdjacencyMatrixGraph<T, WeightType>::insertNode(GraphNode<T>* node) {
    if(!nodesList.isEmpty())
        assert(!nodesList.belongsTo(*node)); // PRE-COND: Node doesn't belong to nodesList

    //nodesList.insertNodeAfter(nodesList.lastNodeList(), node);
    nodesList.insert(*node);

    int nNodes = Graph<T, WeightType>::getNodesInside() + 1;
    node->setId(nNodes - 1);
    Graph<T, WeightType>::setNodesInside(nNodes);

    adjacencyMatrix.push_back(*(new vector<WeightType>(nNodes, NO_LINK))); // Add a new row with the new dim
    for (int i = 0; i < nNodes - 1; ++i)
        adjacencyMatrix[i].push_back(NO_LINK);// add element for each row

}

template<class T, class WeightType>
void AdjacencyMatrixGraph<T, WeightType>::insertLink(GraphNode<T>* node1, GraphNode<T>* node2, WeightType w) {
    Edge<T, WeightType> e(*node1, *node2, w);
    edgesList.insertNodeAfter(edgesList.lastNodeList(), e);

    setWeight(*node1, *node2, w);

    node1->setLinks(node1->getLinks() + 1);
}

template<class T, class WeightType>
void AdjacencyMatrixGraph<T, WeightType>::removeNode(GraphNode<T>* node) {

    //Pre-conds
    assert( existsNode(*node) );
    assert( ! node->hasLinks() );

    nodesList.remove(*node);
    int nNodes = Graph<T, WeightType>::getNodesInside();
    adjacencyMatrix.erase(adjacencyMatrix.begin() +  node->getId());// remove elem for each row

    for (int i = 0; i < nNodes - 1; ++i)
        adjacencyMatrix[i].erase(adjacencyMatrix[i].begin() + node->getId());// remove elem for each row

    delete node;

    Graph<T, WeightType>::setNodesInside(nNodes - 1);
}

template<class T, class WeightType>
void AdjacencyMatrixGraph<T, WeightType>::removeLink(GraphNode<T>* node1, GraphNode<T>* node2) {

    assert(node1->getLinks() > 0);
    assert(node2->getLinks() > 0);
    assert(existsLink(*node1, *node2));

    setWeight(*node1, *node2, NO_LINK);
    Edge<T, WeightType> e(*node1, *node2);

    edgesList.deleteNodeAt(edgesList.getFirstPositionByElem(e));
    node1->setLinks(node1->getLinks() - 1);

}

template<class T, class WeightType>
void AdjacencyMatrixGraph<T, WeightType>::setWeight(GraphNode<T> node1, GraphNode<T> node2, WeightType w) {
    adjacencyMatrix.at(node1.getId()).at(node2.getId()) = w;
}

template<class T, class WeightType>
WeightType AdjacencyMatrixGraph<T, WeightType>::getLinkWeight(GraphNode<T> node1, GraphNode<T> node2){
    return adjacencyMatrix.at(node1.getId()).at(node2.getId());
}


template<class T, class WeightType>
PointerList<GraphNode<T>, 0> AdjacencyMatrixGraph<T, WeightType>::getAllNodes() {
    return nodesList.getAllElementsAsPointerList();
}

template<class T, class WeightType>
PointerList<GraphNode<T>, 0> AdjacencyMatrixGraph<T, WeightType>::adjacents(GraphNode<T> node) {


    PointerList<GraphNode<T>, 0> adjacents;

    auto allNodes = nodesList.getAllElements();

    vector<WeightType> row = adjacencyMatrix.at(node.getId());
    for (GraphNode<T> innerNode : allNodes) {
        if(row.at(innerNode.getId()) != NO_LINK){
            adjacents.insertNodeAfter(adjacents.lastNodeList(), innerNode);
        }
    }

    return adjacents;
}

template<class T, class WeightType>
bool AdjacencyMatrixGraph<T, WeightType>::existsNode(GraphNode<T> node) {
    return nodesList.find(node);
}

template<class T, class WeightType>
bool AdjacencyMatrixGraph<T, WeightType>::existsLink(GraphNode<T> node1, GraphNode<T> node2) {
    return getLinkWeight(node1, node2) != NO_LINK;
}

template<class T, class WeightType>
T AdjacencyMatrixGraph<T, WeightType>::readValue(GraphNode<T> node) {
    return node.getElem();
}

template<class T, class WeightType>
void AdjacencyMatrixGraph<T, WeightType>::writeValue(GraphNode<T>* node, T t) {
   node->setElem(t);
}

template<class T, class WeightType>
AdjacencyMatrixGraph<T, WeightType>::~AdjacencyMatrixGraph() {
    //delete edgesList;
    //delete nodesList;
    //delete adjacencyMatrix;
}
