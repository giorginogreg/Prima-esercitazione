cmake_minimum_required(VERSION 3.21)
project(pointerQueue)

set(CMAKE_CXX_STANDARD 14)

FILE(GLOB GENERIC_SRCFILES
        "../src/*.tpp")
FILE(GLOB GENERIC_HEADER_FILES
        "../include/*.h")

FILE(GLOB SRCFILES
        "src/*.cpp")

FILE(GLOB HEADER_FILES
        "include/*.h")

add_executable(
    pointerQueue
    ${GENERIC_HEADER_FILES} ${GENERIC_SRCFILES}
    ${SRCFILES} ${HEADER_FILES}
    pointerQueue.cpp
)

add_executable(
    tester_pointerQueue
    ${SRCFILES} ${HEADER_FILES}
    tests/tester_pointerQueue.cpp
)
