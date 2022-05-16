cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 14)
project(Heap)

FILE(GLOB SRCFILES
        "src/Newton/*.cpp")

FILE(GLOB TEST_FILES
        "Tests*.cpp")


add_executable(
        Heap
        ${TEST_FILES}
        ${SRCFILES}
        include/HeapPrioriqueue.h
        src/HeapPrioriqueue.tpp
)
