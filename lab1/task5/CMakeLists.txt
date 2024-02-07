cmake_minimum_required(VERSION 3.27)
project(task5 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(task5
        enums.h
        func.c
        lab1task5.c)
