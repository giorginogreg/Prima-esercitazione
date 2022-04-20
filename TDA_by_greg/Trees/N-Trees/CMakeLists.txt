cmake_minimum_required(VERSION 3.21)
project(NTrees)

set(CMAKE_CXX_STANDARD 14)

FILE(GLOB SUPERSRCFILES
        "../include/*.h")

FILE(GLOB SRCFILES
        "include/*.h")

add_executable(
        NTrees
        ${SUPERSRCFILES}
        ${SRCFILES}
        main.cpp src/N-Tree.tpp)

