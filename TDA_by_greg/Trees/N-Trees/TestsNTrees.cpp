#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "./../../../catch.hpp"
#include "./include/N-Tree.h"

using std::string;

TEST_CASE( "N-Trees: test that a tree is empty after the creation" ) {
    auto ntree = N_Tree<string>();
    REQUIRE( ntree.empty() );
    REQUIRE( ntree.depth(ntree.root()) == 0 );
}

