cmake_minimum_required(VERSION 3.21)
project(PointerDictionary)

set(CMAKE_CXX_STANDARD 14)

FILE(GLOB SRCFILES
        "src/*.cpp")

FILE(GLOB SUPER_SRCFILES
        "include/*.h")

add_executable(PointerDictionary main.cpp
        ${SRCFILES}
        ${SUPER_SRCFILES}
        src/PointerDictionary.cpp)
