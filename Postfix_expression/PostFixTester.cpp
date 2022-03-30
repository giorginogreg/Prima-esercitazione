//
// Created by Greg on 23/03/22.
//

#define CATCH_CONFIG_MAIN  // These tells Catch to provide a main() - only do this in one cpp file
#include "../catch.hpp"
#include "Postfix.h"
#include <string>

using namespace std;
TEST_CASE( "Stack List" ) {

    Postfix<string, 1> s;
    s.push("5");
    s.push("9");
    s.push("8");
    s.push("+");
    s.push("4");
    s.push("6");
    s.push("*");
    s.push("*");
    s.push("7");
    s.push("+");
    s.push("*");

    REQUIRE(2075 == stoi(s.pop()));

}
TEST_CASE( "Stack List2" ) {


    Postfix<string, 0> s2;
    s2.push("5");
    s2.push("10");
    s2.push("2");
    s2.push("*");
    s2.push("+");

    REQUIRE(25 == stoi(s2.pop()));


}
TEST_CASE( "Stack List3" ) {


    Postfix<string, 0> s3;
    s3.push("20");
    s3.push("15");
    s3.push("100");
    s3.push("5");
    s3.push("-");
    s3.push("*");
    s3.push("+");
    s3.push("21");
    s3.push("-");

    REQUIRE(1424 == stoi(s3.pop()));


}
