cmake_minimum_required(VERSION 3.21)
project(queue)

set(CMAKE_CXX_STANDARD 14)
FILE(GLOB GENERIC_SRCFILES
        "../src/*.tpp")
FILE(GLOB GENERIC_HEADER_FILES
        "../include/*.h")

FILE(GLOB SPECIFIC_SRCFILES
        "src/*.tpp")
FILE(GLOB SPECIFIC_HEADER_FILES
        "include/*.h")

add_executable(
        queue
        main.cpp
        ${GENERIC_SRCFILES} ${GENERIC_HEADER_FILES}
        ${SPECIFIC_SRCFILES} ${SPECIFIC_HEADER_FILES}
)
add_executable(
        TestQueue
        ../../../Exception/IllegalStateException.h
        Test_Cases.cpp
        ${GENERIC_SRCFILES} ${GENERIC_HEADER_FILES}
        ${SPECIFIC_SRCFILES} ${SPECIFIC_HEADER_FILES}
)
