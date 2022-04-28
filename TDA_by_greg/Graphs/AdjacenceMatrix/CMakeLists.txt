cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 14)
project(AdjacencyMatrixGraph)

FILE(GLOB SRCFILES
        "include/*.h")

add_executable(
        AdjacencyMatrixGraph
        main.cpp
        ${SRCFILES}
        ../../include/GraphNode.h
)
