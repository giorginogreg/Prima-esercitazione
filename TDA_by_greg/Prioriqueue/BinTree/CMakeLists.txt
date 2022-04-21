cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 14)
set(PROJECT_NAME "BinTreePrioriqueue")

project(${PROJECT_NAME})

FILE(GLOB SRCFILES
        "include/*.h")

add_executable(
        ${PROJECT_NAME}

        ${SRCFILES} main.cpp)
