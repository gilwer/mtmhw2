cmake_minimum_required(VERSION 3.7)
project(hw2c)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c )

add_definitions(-Wall -std=c99 -Werror  -pedantic-errors)

add_executable(hw2 ${SOURCE_FILES})