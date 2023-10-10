cmake_minimum_required(VERSION 3.2)
add_compile_definitions(-lm)

project(labs LANGUAGES C)


add_executable(lab1 lab1.c enums.h)

add_library(mylib STATIC func_lib.c)


target_link_libraries(lab1 PUBLIC mylib)



