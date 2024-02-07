cmake_minimum_required(VERSION 3.27)
project(task7 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(task7
        enums.h
        func.c
        lab1task7.c)
