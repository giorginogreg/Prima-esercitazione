cmake_minimum_required(VERSION 3.21)
project(pointerQueue)

set(CMAKE_CXX_STANDARD 14)

FILE(GLOB GENERIC_SRCFILES
        "../src/*.tpp")
FILE(GLOB GENERIC_HEADER_FILES
        "../include/*.h")

FILE(GLOB SRCFILES
        "src/*.tpp")

FILE(GLOB HEADER_FILES
        "include/*.h")

add_executable(
    pointerQueue
    ${GENERIC_HEADER_FILES} ${GENERIC_SRCFILES}
    ${SRCFILES} ${HEADER_FILES}
    main.cpp
)
