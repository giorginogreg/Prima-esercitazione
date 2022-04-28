//
// Created by Greg on 25/04/22.
//


#include <iostream>
#include <string>
#include "include/AdjacencyMatrixGraph.h"
using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
    AdjacencyMatrixGraph<int, int> graph;
    auto node1 =  new GraphNode<int>(1);
    auto node2 =  new GraphNode<int>(2);
    graph.insertNode(node1);
    graph.insertNode(node2);

    graph.insertLink(node1, node2);
    graph.insertLink(node2, node1);

    assert(graph.existsLink(*node1, *node2));
    assert(graph.existsLink(*node2, *node1));

    graph.removeLink(node1, node2);
    graph.removeNode(node1);

    return 0;
}
