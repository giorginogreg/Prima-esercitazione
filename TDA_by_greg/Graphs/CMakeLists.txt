cmake_minimum_required(VERSION 3.21)
project(algorithm_data_structures)

set(CMAKE_CXX_STANDARD 14)

FILE(GLOB SRCFILES
        "src/Newton/*.cpp")

add_executable(algorithm_data_structures main.cpp
        ${SRCFILES})
