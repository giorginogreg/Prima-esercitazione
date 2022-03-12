#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../catch.hpp"

#include "Matrix.h"

TEST_CASE( "Matrix elems definition" ) {
    Matrix m(10, 10);
    REQUIRE( m.read_value_at(0,0) == 0);
    REQUIRE( m.read_value_at(9,9) == 0);
    REQUIRE_THROWS_WITH( m.read_value_at(10,10), "Error: out of index");
    m.write_value_at(1,1, 20.2f);
    REQUIRE( m.read_value_at(1,1) == 20.2f);
}

TEST_CASE( "Matrix elems scalar use" ) {
    Matrix m2(3,3,1);
    
    REQUIRE( m2.read_value_at(0,0) == 1);
    m2.scalar_product(5);
    REQUIRE( m2.read_value_at(0,0) == 5);

}