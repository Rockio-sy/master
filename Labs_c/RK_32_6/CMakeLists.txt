cmake_minimum_required(VERSION 3.27)
project(tryToremove C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(tryToremove
        err.h
        io.c
        io.h
        main.c)
