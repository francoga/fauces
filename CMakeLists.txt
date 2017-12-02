cmake_minimum_required(VERSION 3.8)
project(fauces)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/fauces.c
        src/fauces.h tests/tests.c tests/helpers.h tests/helpers.c)

add_executable(fauces ${SOURCE_FILES})