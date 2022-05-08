#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../../catch.hpp"

#define DICTIONARY_TESTS
// Dictionary tests

#include "../Dictionary/PointerDictionary/include/PointerDictionary.h"


// -----------------
#define GRAPH_TESTS

// Graph tests

#include "../Graphs/AdjacenceMatrix/include/AdjacencyMatrixGraph.h"


// -----------------
#define VECTOR_LIST_TESTS
// List tests

#include "../Lists/vector_implementation/include/VectorList.h"
#include "../Exception/OutOfBoundException.h"

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


// -----------------
#define POINTER_LINKED_LIST_TESTS
// Linked List

#include "../Lists/pointer_implementation/Linked List/include/LinkedList.h"

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


// -----------------
#define POINTER_QUEUE_TESTS
// Pointer Queue Tests
#include "../Lists/Queue/pointer_implementation/include/PointerQueue.h"

TEST_CASE( "List initialization" ) {
    PointerQueue<int, 10> p;
    REQUIRE(p.isEmpty());
}

TEST_CASE( "Push and read value" ) {
    PointerQueue<int, 10> p;
    p.enqueue(50);
    REQUIRE(p.readQueue() == 50);
}

TEST_CASE( "Enqueue and dequeue" ) {
    PointerQueue<int, 10> p;
    p.enqueue(50);
    REQUIRE(p.dequeue() == 50);
    p.enqueue(100);

    p.enqueue(150);
    REQUIRE(p.dequeue() == 100);
    REQUIRE(p.dequeue() == 150);

}

// -----------------
#define VECTOR_QUEUE_TESTS
// Vector Queue Tests

TEST_CASE( "Queue initialization" ) {
    REQUIRE(false);
}

TEST_CASE( "Dequeue with empty queue not possible" ) {
    REQUIRE(false);
}

TEST_CASE( "Enqueue more than the size" ) {
    REQUIRE(false);
}

// -----------------
#define STACK_TESTS

#include "../Lists/pointer_implementation/Stack/include/StackList.h"

TEST_CASE( "List initialization" ) {

    //StackList<int, 10> stackList;

    //REQUIRE(stackList.getDimension() == size);
    //REQUIRE(stackList.getElementsInside() == 0);

    REQUIRE_FALSE(true);
}

// -----------------
#define PRIORIQUEUE_BIN_TREE

#include "../Prioriqueue/BinTree/include/BinTreePrioriqueue.h"
#include "../Prioriqueue/BinTree/src/BinTreePrioriqueue.tpp"



// -----------------
#define PRIORIQUEUE_HEAP

#include "../Prioriqueue/Heap/include/HeapPrioriqueue.h"
#include "../Prioriqueue/Heap/src/HeapPrioriqueue.tpp"



// ------------------
#define SETS_POINTER

#include "../Sets/pointerSet/include/PointerSet.h"
#include "../Sets/pointerSet/src/PointerSet.tpp"



// ------------------

#define SETS_POINTER

#include "../Sets/pointerSet/include/PointerSet.h"
#include "../Sets/pointerSet/src/PointerSet.tpp"



// ------------------

#define BINSEARCH_TREES

#include "../Trees/BinarySearchTrees/include/BinarySearchTree.h"



// ------------------
#define N_TREES

//#include "../Trees/N-Trees/include/N-Tree.h"



// ------------------