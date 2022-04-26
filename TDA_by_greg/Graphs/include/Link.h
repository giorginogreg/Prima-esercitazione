//
// Created by Greg on 25/04/22.
//

#ifndef GRAPHS_LINK_H
#define GRAPHS_LINK_H

#include "../../include/Node.h"

using TDA_Greg::Node;

// Classe template con due nodi e il peso
template<class T, class WeightType>
class Edge {

private:
    Node<T> n1;
    Node<T> n2;
    WeightType weight;

public:
    Edge(Node<T> _n1, Node<T> _n2, WeightType w): n1(_n1), n2(_n2), weight(w){};

};

#endif //GRAPHS_LINK_H
