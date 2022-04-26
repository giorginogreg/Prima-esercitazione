cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 14)
project(Graphs)

FILE(GLOB SRCFILES
        "src/Newton/*.cpp")

add_executable(
        Graphs
        main.cpp
        ${SRCFILES} main.cpp src/Graph.tpp include/Graph.h include/Link.h AdjacenceMatrix/main.cpp)
