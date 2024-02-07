cmake_minimum_required(VERSION 3.27)
project(task6 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(task6
        enums.h
        func.c
        lab1task6.c)
