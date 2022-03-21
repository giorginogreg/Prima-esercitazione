#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../../../catch.hpp"

#include "include/VectorList.h"
#include "src/VectorList.cpp"
#include "include/OutOfBoundException.h"

TEST_CASE( "List initialization" ) {

    const int size = 10;
    VectorList<int, 10> vectorList;

    REQUIRE(vectorList.getDimension() == size);
    REQUIRE(vectorList.getElementsInside() == 0);

}


TEST_CASE( "Is list empty?" ) {

    const int size = 0;
    VectorList<int, size> vectorList;

    REQUIRE(vectorList.isEmpty() == true);

    vectorList.insertNodeAfter(0, 1);

    REQUIRE(vectorList.readValueAt(0) == 1);
    REQUIRE(vectorList.isEmpty() == false);
    REQUIRE(vectorList.getElementsInside() == 1);

    vectorList.deleteNodeAt(0);

    REQUIRE(vectorList.isEmpty() == true);
    REQUIRE(vectorList.getElementsInside() == 0);
    REQUIRE(vectorList.getDimension() == size);

}

TEST_CASE( "Array out of bound" ) {

    const int size = 3;
    VectorList<int, size> vectorList;
    REQUIRE_THROWS_AS( vectorList.writeValueAt(4, 1), OutOfBoundException);

}

TEST_CASE( "List Shifting" ) {

    const int size = 3;
    VectorList<int, size> vectorList;
    vectorList.writeValueAt(0, 1);
    vectorList.writeValueAt(1, 2);
    vectorList.writeValueAt(2, 3);

    vectorList.shiftElementsToRight();

    REQUIRE(vectorList.readValueAt(1) == 1);
    REQUIRE(vectorList.readValueAt(2) == 2);

}
