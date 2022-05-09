cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 14)
project(Tests)

FILE(GLOB SRCFILES
        "include/*.h")

add_executable(
    Tests
    Tests.cpp
)
