//
// Created by Greg on 23/03/22.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../../../../catch.hpp"

#include "include/StackList.h"

TEST_CASE( "Stack: List initialization", "[vector]" ) {

    auto stackList = new StackList<int>();

    SECTION( "Is list empty after initialization" ) {
        REQUIRE(stackList->empty());
    }

    SECTION( "Stack: Testing that single push works" ) {
        stackList->push(1);
        REQUIRE(stackList->pop() == 1);
    }

    SECTION( "Stack: Testing that multiple pushes works" ) {
        stackList->push(1);
        stackList->push(2);
        stackList->push(3);
        REQUIRE(stackList->pop() == 3);
        REQUIRE(stackList->pop() == 2);
        REQUIRE(stackList->pop() == 1);
    }

    SECTION( "Stack: Testing that pop with empty list triggers error" ) {
        //REQUIRE_THROWS_AS(stackList->pop(), IllegalAction)
    }

    SECTION( "Stack: Testing that top works" ) {
        stackList->push(1);
        stackList->push(2);
        stackList->push(3);
        REQUIRE(stackList->top() == 3);
    }



}