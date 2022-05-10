//
// Created by Greg on 03/04/22.
//

#include "../include/PointerQueue.h"

#define CATCH_CONFIG_MAIN
#include "../../../../../catch.hpp"

TEST_CASE( "Pointer Queue: List initialization" ) {
    PointerQueue<int, 10> p;
    REQUIRE(p.isEmpty());
}

TEST_CASE( "Pointer Queue: Push and read value" ) {
    PointerQueue<int, 10> p;
    p.enqueue(50);
    REQUIRE(p.readQueue() == 50);
}

TEST_CASE( "Pointer Queue: Enqueue and dequeue" ) {
    PointerQueue<int, 10> p;
    p.enqueue(50);
    REQUIRE(p.dequeue() == 50);
    p.enqueue(100);

    p.enqueue(150);
    REQUIRE(p.dequeue() == 100);
    REQUIRE(p.dequeue() == 150);

}

