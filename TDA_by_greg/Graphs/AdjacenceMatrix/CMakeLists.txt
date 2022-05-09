cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 14)
project(AdjacencyMatrixGraph)

FILE(GLOB TEST_FILES
        "Tests*.cpp")

FILE(GLOB SRCFILES
        "include/*.h")

add_executable(
        AdjacencyMatrixGraph
        main.cpp
        ${SRCFILES}
        ../../include/GraphNode.h
)
add_executable(
        TestsAdjacencyMatrixGraph
        ${TEST_FILES}
        ${SRCFILES}
        ../../include/GraphNode.h
)

