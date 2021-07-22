cmake_minimum_required(VERSION 3.19)
project(RepPer)

set(CMAKE_CXX_STANDARD 14)


set(INCLUDES include/Permutation.h include/YoungTableau.h)

set(SOURCES src/Permutation.cpp src/YoungTableau.cpp)

add_executable(
        RepPer
        main.cpp
        ${SOURCES}
        ${INCLUDES}
)

target_compile_options(RepPer PRIVATE -Wall)


add_subdirectory(googletest)

set(TESTS tests/PermutationTest.cpp tests/YoungTableauTest.cpp)

add_executable(
        Tests
        ${TESTS}
        ${SOURCES}
        ${INCLUDES}
)

target_link_libraries(
        Tests PRIVATE
        gtest
        gmock
        gtest_main
)

target_compile_options(Tests PRIVATE -Wall)
