#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "./../../../catch.hpp"
#include "./include/HeapPrioriqueue.h"

TEST_CASE( "Prioriqueue - Heap: create a new queue" ) {
    auto hp = new HeapPrioriqueue<int>(5);
    hp->insert(1);
    hp->insert(2);

    REQUIRE(hp->getMinimum() == 1);
}

TEST_CASE( "Prioriqueue - Heap: test if the deleteMinimum elem. works" ) {
    auto hp = new HeapPrioriqueue<int>(5);
    hp->insert(1);
    hp->insert(2);
    hp->insert(3);
    hp->insert(2);

    REQUIRE(hp->getMinimum() == 1);
    hp->deleteMinimum();
    REQUIRE(hp->getMinimum() == 2);
}

