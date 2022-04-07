//
// Created by Greg on 23/03/22.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../../../../catch.hpp"

#include "include/StackList.h"
#include "src/StackList.cpp"

TEST_CASE( "List initialization" ) {

    StackList<int, 10> stackList;

    //REQUIRE(linkedList.getDimension() == size);
    //REQUIRE(stackList.getElementsInside() == 0);

}
