#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "./../../../catch.hpp"

#include "./include/AdjacencyMatrixGraph.h"

TEST_CASE( "Adjacency Matrix Graph" ) {

    typedef string T;
    auto g = new AdjacencyMatrixGraph<T, int>();

    SECTION( "Creation of a graph: initialization" ) {
        REQUIRE(g->isEmpty());
    }

    SECTION( "Inserting a node in the graph and asserting that it exists" ) {
        auto n1 = new GraphNode<T>("A");
        g->insertNode(n1);
        REQUIRE(g->existsNode(*n1));
    }
}


TEST_CASE( "Adjacency Matrix Graph with two nodes" ) {

    typedef string T;
    auto g = new AdjacencyMatrixGraph<T, int>();

    auto n1 = new GraphNode<T>("N1");
    auto n2 = new GraphNode<T>("N2");
    auto n3 = new GraphNode<T>("N3");

    g->insertNode(n1);
    g->insertNode(n2);

    SECTION( "Inserting two nodes in the graph and create a link between them" ) {

        REQUIRE_FALSE(g->existsLink(*n1, *n2));
        g->insertLink(n1, n2);
        REQUIRE(g->existsLink(*n1, *n2));
        REQUIRE(g->getLinkWeight(*n1, *n2) == 1);
    }

    SECTION( "Insert a link between the two nodes different from the default" ) {
        g->insertLink(n1, n2, 5);
        REQUIRE(g->existsLink(*n1, *n2));
        REQUIRE(g->getLinkWeight(*n1, *n2) == 5);
    }

    SECTION( "Assert that the nodes exist in the pointerlist" ) {
        REQUIRE(g->existsNode(*n1));
        REQUIRE(g->existsNode(*n2));
        REQUIRE_FALSE(g->existsNode(*n3));
    }

    SECTION( "Assert reading the value in the node" ) {
        REQUIRE(g->readValue(*n1) == "N1");
        REQUIRE(g->readValue(*n2) == "N2");
        REQUIRE_FALSE(g->readValue(*n2) == "N1");
    }

    SECTION( "Asserting that changing the value in a node returns the correct value" ) {
        g->writeValue(n1, "A_mod");
        REQUIRE(g->readValue(*n1) == "A_mod");
    }

    SECTION( "Asserting that removing a node that exists works" ) {
        g->removeNode(n1);
        REQUIRE_FALSE(g->existsNode(*n1));
    }

    g->insertLink(n1, n2);
    auto adjacencyPl = g->adjacents(*n1);

    SECTION( "Asserting that removing a link that exists between 2 nodes works" ) {
        g->removeLink(n1, n2);
        REQUIRE(g->existsNode(*n1));
        REQUIRE(g->existsNode(*n2));
        REQUIRE_FALSE(g->existsLink(*n1, *n2));
    }

   /* SECTION( "Assert that the nodes exist in the pointerlist of the adjacency list" ) {
        REQUIRE(adjacencyPl.find(*n2));
        REQUIRE_FALSE(adjacencyPl.find(*n3));
    }*/
}


