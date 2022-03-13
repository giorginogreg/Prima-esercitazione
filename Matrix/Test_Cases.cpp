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

TEST_CASE( "Matrix multiplication" ) {

    Matrix m(3, 3);
    m.write_value_at(0, 0, 1);
    m.write_value_at(0, 1, 0);
    m.write_value_at(0, 2, 1);
    
    m.write_value_at(1, 0, 1);
    m.write_value_at(1, 1, 5);
    m.write_value_at(1, 2, -1);
  
    m.write_value_at(2, 0, 3);
    m.write_value_at(2, 1, 2);
    m.write_value_at(2, 2, 0);
  
    Matrix m2(3, 2);
    m2.write_value_at(0, 0, 7);
    m2.write_value_at(0, 1, 1);
    
    m2.write_value_at(1, 0, 1);
    m2.write_value_at(1, 1, 0);

    m2.write_value_at(2, 0, 0);
    m2.write_value_at(2, 1, 4);
    
    Matrix multiplied(3, 2);
    multiplied = m * m2;
    
    REQUIRE( multiplied.read_value_at(0,0) == 7);
    REQUIRE( multiplied.read_value_at(0,1) == 5);
    REQUIRE( multiplied.read_value_at(1,0) == 12);
    REQUIRE( multiplied.read_value_at(1,1) == -3);
    REQUIRE( multiplied.read_value_at(2,0) == 23);
    REQUIRE( multiplied.read_value_at(2,1) == 3);

}