cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 14)
project(PointerList)

FILE(GLOB TEST_FILES
        "Tests*.cpp")

FILE(GLOB SRCFILES
        "include/*.h")

add_executable(
        TestsPointerList
        ${TEST_FILES}
        ${SRCFILES})
