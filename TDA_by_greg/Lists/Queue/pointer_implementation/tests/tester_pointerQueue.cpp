//
// Created by Greg on 03/04/22.
//

#include "../include/PointerQueue.h"

#define CATCH_CONFIG_MAIN
#include "/Users/greg/Desktop/Universita/ASD/Esercitazioni_ASD/catch.hpp"

TEST_CASE( "List initialization" ) {

    PointerQueue<int, 10> p;

    REQUIRE_FALSE(p.isEmpty());
    //REQUIRE(stackList.getElementsInside() == 0);

}
