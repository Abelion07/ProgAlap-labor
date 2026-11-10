cmake_minimum_required(VERSION 4.3)
project(01Konyvtar C)

set(CMAKE_C_STANDARD 11)

add_executable(01Konyvtar main.c
        konyv.c
        konyv.h
        menu.c
        menu.h
        fajl.c
        fajl.h
        cmake-build-debug/olvasas.c
        cmake-build-debug/olvasas.h)
