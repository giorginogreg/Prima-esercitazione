#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "./../../../../catch.hpp"
#include "include/PointerList.h"

TEST_CASE( "Pointer List Initialization" ) {
    int maxElems = 10;
    auto pl = new PointerList<int>(maxElems);
    REQUIRE( pl->isEmpty() );
    REQUIRE( pl->getMaxElementsInside() == maxElems );
    REQUIRE( pl->getElementsInside() == 0 );
}

TEST_CASE( "Pointer List test of node creations" ) {
    int maxElems = 10;
    typedef int T;
    auto pl = new PointerList<T>(maxElems);

    pl->insertNodeAfter(pl->getHead(), 1);

    REQUIRE_FALSE( pl->isEmpty() );
    auto sentinel = pl->getHead();
    REQUIRE(pl->readValueAt(sentinel->getNextPos()) == 1);
    REQUIRE( pl->getElementsInside() == 1 );
}

TEST_CASE( "Pointer List write in a value after node inserted" ) {
    int maxElems = 10;
    typedef int T;
    auto pl = new PointerList<T>(maxElems);

    pl->insertNodeAfter(pl->getHead(), 1);

    auto sentinel = pl->getHead();
    pl->writeValueAt(pl->getFirstPositionByElem(1), 2);
    REQUIRE(pl->readValueAt(sentinel->getNextPos()) == 2);
}

TEST_CASE( "Pointer List node deleting test" ) {
    int maxElems = 10;
    typedef int T;
    auto pl = new PointerList<T>(maxElems);
    auto sentinel = pl->getHead();

    pl->insertNodeAfter(sentinel, 1);

    REQUIRE(pl->find(1));
    pl->deleteNodeAt(sentinel->getNextPos());
    REQUIRE_FALSE(pl->find(1));
}

