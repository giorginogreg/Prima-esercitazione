//
// Created by Greg on 03/04/22.
//

#include "../include/PointerQueue.h"

#define CATCH_CONFIG_MAIN
#include "../../../../../catch.hpp"

TEST_CASE( "Queue with vector", "[vector]" ) {

    auto p = new PointerQueue<int>(10);

    SECTION( "Pointer Queue: List initialization" ) {
        REQUIRE(p->isEmpty());
    }

    SECTION( "Pointer Queue: Push and read value" ) {
        p->enqueue(50);
        REQUIRE(p->readQueue() == 50);
    }

    SECTION( "Pointer Queue: Enqueue and dequeue" ) {
        p->enqueue(50);
        REQUIRE(p->dequeue() == 50);
        p->enqueue(100);

        p->enqueue(150);
        REQUIRE(p->dequeue() == 100);
        REQUIRE(p->dequeue() == 150);

    }

}
