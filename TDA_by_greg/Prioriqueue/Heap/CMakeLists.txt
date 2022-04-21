cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 14)
project(Heap)

FILE(GLOB SRCFILES
        "src/Newton/*.cpp")

add_executable(
        Heap
        main.cpp
        ${SRCFILES} main.cpp include/HeapPrioriqueue.h src/HeapPrioriqueue.tpp)
