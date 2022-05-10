#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "./../../../catch.hpp"
#include "include/PointerDictionary.h"

using std::string;

TEST_CASE( "Testing that a pointer is empty after initialization" ) {
    auto p = new PointerDictionary<string, int>(10);

    REQUIRE(p->isEmpty());
}

TEST_CASE( "Testing that putting a new pair into a dictionary is working" ) {
    auto p = new PointerDictionary<string, int>(10);

    Pair<string, int> pair {
        ._key = "A",
        ._value = 10
    };
    p->put(pair);

    REQUIRE(p->getValue("A") == 10);
    REQUIRE_FALSE(p->isEmpty());
}

TEST_CASE( "Testing that inserting multiple values in a dictionary is working" ) {
    auto p = new PointerDictionary<string, int>(10);

    Pair<string, int> pair {
        ._key = "A",
        ._value = 10
    };
    p->put(pair);

    Pair<string, int> pair2 {
        ._key = "B",
        ._value = 20
    };
    p->put(pair2);

    REQUIRE(p->getValue("A") == 10);
    REQUIRE(p->getValue("B") == 20);
}

TEST_CASE( "Testing that updating a value is working" ) {
    auto p = new PointerDictionary<string, int>(10);

    Pair<string, int> pair {
        ._key = "A",
        ._value = 10
    };
    p->put(pair);

    Pair<string, int> pair2 {
        ._key = "B",
        ._value = 20
    };
    p->put(pair2);

    p->updatePair(
            Pair<string, int> { ._key = "B", ._value = 50 }
    );

    REQUIRE(p->getValue("A") == 10);
    REQUIRE(p->getValue("B") == 50);

    Pair<string, int> pair3 {
            ._key = "B",
            ._value = 100
    };
    p->put(pair3);

    REQUIRE(p->getValue("B") == 100);
    REQUIRE(p->getValue("A") == 10);

    Pair<string, int> pair4 {
            ._key = "C",
            ._value = 500
    };
    p->put(pair4);
    REQUIRE(p->getValue("C") == 500);

}
