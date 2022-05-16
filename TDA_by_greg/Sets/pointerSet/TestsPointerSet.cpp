#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "./../../../catch.hpp"
#include "./include/PointerSet.h"

TEST_CASE( "PointerSet: test if after the set creation, it's empty" ) {
    auto ps = new PointerSet<int>();

    REQUIRE( ps->isEmpty() );
}

TEST_CASE( "PointerSet: testing that belongsTo is working" ) {
    auto ps = new PointerSet<int>();

    ps->insert(1);
    REQUIRE(ps->belongsTo(1));
    REQUIRE_FALSE(ps->belongsTo(2));
}


TEST_CASE( "PointerSet: removing one element that exists" ) {
    auto ps = new PointerSet<int>();

    ps->insert(1);
    ps->remove(1);
    REQUIRE_FALSE(ps->belongsTo(1));

}

TEST_CASE( "PointerSet: asserting that unified set is working" ) {
    auto ps = new PointerSet<int>();
    auto ps2 = new PointerSet<int>();
    ps->insert(1);
    ps->insert(2);
    ps->insert(3);
    ps->insert(4);
    ps->insert(5);


    ps2->insert(3);
    ps2->insert(1);
    ps2->insert(33);

    auto unified_set = dynamic_cast<PointerSet<int>*>(ps->union_op(ps2));
    REQUIRE(unified_set->belongsTo(1));
    REQUIRE(unified_set->belongsTo(2));
    REQUIRE(unified_set->belongsTo(3));
    REQUIRE(unified_set->belongsTo(33));
    REQUIRE(unified_set->belongsTo(4));
    REQUIRE(unified_set->belongsTo(5));
}


TEST_CASE( "PointerSet: asserting that intersection between sets is working" ) {
    auto ps = new PointerSet<int>();
    auto ps2 = new PointerSet<int>();
    ps->insert(1);
    ps->insert(2);
    ps->insert(3);
    ps->insert(4);
    ps->insert(5);


    ps2->insert(1);
    ps2->insert(3);
    ps2->insert(33);

    auto unified_set = dynamic_cast<PointerSet<int>*>(ps->intersect(ps2));
    REQUIRE(unified_set->belongsTo(1));
    REQUIRE(unified_set->belongsTo(3));
    REQUIRE_FALSE(unified_set->belongsTo(4));
    REQUIRE_FALSE(unified_set->belongsTo(33));
    REQUIRE_FALSE(unified_set->belongsTo(5));
}


TEST_CASE( "PointerSet: asserting that difference between sets is working" ) {
    auto ps = new PointerSet<int>();
    auto ps2 = new PointerSet<int>();
    ps->insert(1);
    ps->insert(2);
    ps->insert(3);
    ps->insert(4);
    ps->insert(5);


    ps2->insert(1);
    ps2->insert(3);
    ps2->insert(33);

    auto unified_set = dynamic_cast<PointerSet<int>*>(ps->difference(ps2));
    REQUIRE_FALSE(unified_set->belongsTo(1));
    REQUIRE(unified_set->belongsTo(2));
    REQUIRE(unified_set->belongsTo(4));
    REQUIRE(unified_set->belongsTo(5));
    REQUIRE_FALSE(unified_set->belongsTo(33));
    REQUIRE_FALSE(unified_set->belongsTo(3));
}