
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "./../../../../catch.hpp"

#include "include/LinkedList.h"
#include "src/LinkedList.cpp"
#include "./../../../Exception/OutOfBoundException.h"

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

    tempPos = linkedList.firstNodeList()->getPrevPos(); // Raggiungo la head per inserire in testa prima del nodo
    linkedList.insertNodeAfter(tempPos, 0);

    tempPos = linkedList.firstNodeList();
    REQUIRE(linkedList.readValueAt(tempPos) == 0);
    REQUIRE(linkedList.readValueAt(tempPos->getNextPos()) == 1);

}

TEST_CASE( "First insert" ) {
    const int size = 0;
    LinkedList<int, size> linkedList;
    auto tempPos = linkedList.firstNodeList();
    linkedList.insertNodeAfter(tempPos, 1);
    REQUIRE(linkedList.readValueAt(linkedList.firstNodeList()) == 1);
    REQUIRE(linkedList.nextPosition(tempPos) == linkedList.firstNodeList());
    REQUIRE(linkedList.isLastPosition(tempPos->getNextPos()));
    REQUIRE(linkedList.previousPosition(tempPos) == linkedList.firstNodeList()->getPrevPos());
}


TEST_CASE( "Insert after a node at tail" ) {
    const int size = 0;
    LinkedList<int, size> linkedList;
    auto tempPos = linkedList.firstNodeList();
    linkedList.insertNodeAfter(tempPos, 1);
    while(!linkedList.isLastPosition(tempPos)) tempPos = tempPos->getNextPos();
    linkedList.insertNodeAfter(tempPos, 2);
    auto before_last = tempPos;
    tempPos = tempPos->getNextPos();
    REQUIRE(linkedList.readValueAt(tempPos) == 2);
    REQUIRE(linkedList.nextPosition(tempPos->getNextPos()) == linkedList.firstNodeList());
    REQUIRE(linkedList.previousPosition(tempPos) == before_last);
}


TEST_CASE( "Insert a node between the first and the tail" ) {
    const int size = 0;
    LinkedList<int, size> linkedList;
    auto tempPos = linkedList.firstNodeList();
    linkedList.insertNodeAfter(tempPos, 1);
    tempPos = tempPos->getNextPos(); // Last node
    linkedList.insertNodeAfter(tempPos, 2);
    while(!linkedList.isLastPosition(tempPos)) tempPos = tempPos->getNextPos();
    REQUIRE(linkedList.readValueAt(tempPos) == 2);

}