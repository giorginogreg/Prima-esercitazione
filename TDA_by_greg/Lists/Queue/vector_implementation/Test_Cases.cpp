#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../../../../catch.hpp"

#include "include/VectorQueue.h"
#include "../../../Exception/IllegalStateException.h"

TEST_CASE( "Vector Queue ", "[vector]" ) {

    VectorQueue<int>* v;
    v = new VectorQueue<int>(10);

    SECTION( "Queue with vector: initialization" ) {
        REQUIRE(v->isEmpty());
    }

    SECTION( "Queue with vector: test that dequeue with empty queue not possible" ) {
        REQUIRE_THROWS_AS(v->dequeue(), std::out_of_range);
    }

    SECTION( "Queue with vector: test that enqueue one single element and read it" ) {
        v->enqueue(1);
        REQUIRE(v->readQueue() == 1);
    }

    SECTION( "Queue with vector: test that enqueue more elements works" ) {
        v->enqueue(1);
        v->enqueue(2);
        v->enqueue(3);
        REQUIRE(v->readQueue() == 1);
    }

    SECTION( "Queue with vector: test that enqueue and dequeue a single element throws error - readQueue empty list" ) {
        v->enqueue(1);
        v->dequeue();
        REQUIRE_THROWS_AS(v->dequeue(), std::out_of_range);
    }

    SECTION( "Queue with vector: test that enqueue and dequeue multiple elements work" ) {
        v->enqueue(1);
        v->enqueue(2);
        v->enqueue(3);
        v->enqueue(4);
        v->dequeue();

        REQUIRE(v->readQueue() == 2);
    }
}
