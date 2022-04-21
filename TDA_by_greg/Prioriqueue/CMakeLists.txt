cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 14)
set(PROJECT_NAME "Prioriqueue")

project(${PROJECT_NAME})

FILE(GLOB SRCFILES
        "src/Newton/*.cpp")

add_executable(
        ${PROJECT_NAME}
        main.cpp
        ${SRCFILES})
