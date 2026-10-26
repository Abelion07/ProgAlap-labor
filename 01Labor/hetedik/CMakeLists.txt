cmake_minimum_required(VERSION 4.3)
project(hetedik C)

set(CMAKE_C_STANDARD 99)

add_compile_options(-Wall -Werror)

add_executable(hetedik main.c)
