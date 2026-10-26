cmake_minimum_required(VERSION 4.3)
project(modularprogramming C)

set(CMAKE_C_STANDARD 99)

add_executable(modularprogramming main.c
        calculator.c
        calculator.h)
