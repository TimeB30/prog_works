cmake_minimum_required(VERSION 3.25)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
project(lab1)
add_library(math_func enums.h func.c)
add_executable(lab1 lab2.c)
target_link_libraries(lab1 math_func)

