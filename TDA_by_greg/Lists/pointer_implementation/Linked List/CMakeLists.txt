cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 14)
project(LinkedList)

FILE(GLOB SRCFILES
        "include/*.h")

add_executable(
    LinkedList
    LinkedListTester.cpp
    ${SRCFILES}
)
