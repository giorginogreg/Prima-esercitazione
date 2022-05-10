cmake_minimum_required(VERSION 3.21)
project(PointerDictionary)

set(CMAKE_CXX_STANDARD 14)

FILE(GLOB SRCFILES
        "src/*.tpp")

FILE(GLOB SUPER_SRCFILES
        "include/*.h")

FILE(GLOB EXCEPTION_FILE
        "../../Exception/OutOfBoundException.h")

FILE(GLOB TEST_FILES
        "Tests*.cpp")

add_executable(PointerDictionary
    main.cpp
    ${EXCEPTION_FILE}
    ${SRCFILES}
    ${SUPER_SRCFILES}
)

add_executable(
    TestsPointerDictionary
    ${TEST_FILES}
    ${EXCEPTION_FILE}
    ${SRCFILES}
    ${SUPER_SRCFILES}
)
