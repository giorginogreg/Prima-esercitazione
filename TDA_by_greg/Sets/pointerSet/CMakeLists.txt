cmake_minimum_required(VERSION 3.21)
project(PointerSet)

set(CMAKE_CXX_STANDARD 14)

FILE(GLOB SRCFILES
        "./include/*.h")

FILE(GLOB SUPERSRCFILES
        "./../include/*.h")
add_executable(PointerSet main.cpp
        ${SRCFILES}
        ${SUPERSRCFILES}
        )
