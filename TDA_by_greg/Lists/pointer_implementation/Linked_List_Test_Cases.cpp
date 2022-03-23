#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../../../catch.hpp"

#include "include/LinkedList.h"
#include "src/LinkedList.cpp"
#include "../include/OutOfBoundException.h"

TEST_CASE( "List initialization" ) {

    const int size = 10;
    LinkedList<int, 10> linkedList;

    //REQUIRE(linkedList.getDimension() == size);
    REQUIRE(linkedList.getElementsInside() == 0);

}


TEST_CASE( "Is list empty?" ) {

    const int size = 0;
    LinkedList<int, size> linkedList;

    REQUIRE(linkedList.isEmpty() == true);
    auto tempPos = linkedList.firstNodeList();

    linkedList.insertNodeAfter(tempPos, 1);
    tempPos = tempPos->getNextPos();
    REQUIRE(linkedList.readValueAt(tempPos) == 1);
    REQUIRE(linkedList.isEmpty() == false);
    REQUIRE(linkedList.getElementsInside() == 1);

    linkedList.deleteNodeAt(tempPos);

    REQUIRE(linkedList.isEmpty() == true);
    REQUIRE(linkedList.getElementsInside() == 0);
    //REQUIRE(linkedList.getDimension() == size);

}

TEST_CASE( "Array out of bound" ) {
    // Test non implementabile, non ci sono confini sulla lista collegata
}

TEST_CASE( "List Shifting" ) {

    const int size = 3;
    LinkedList<int, size> linkedList;
    auto tempPos = linkedList.firstNodeList();
    linkedList.insertNodeAfter(tempPos, 1);
    tempPos = tempPos->getNextPos();

    linkedList.insertNodeAfter(tempPos, 2);
    tempPos = tempPos->getNextPos();
    linkedList.insertNodeAfter(tempPos, 3);

    tempPos = linkedList.firstNodeList();
    linkedList.insertNodeAfter(tempPos, 0);

    REQUIRE(linkedList.readValueAt(tempPos->getNextPos()) == 0);
    REQUIRE(linkedList.readValueAt(tempPos->getNextPos()->getNextPos()) == 1);

}
