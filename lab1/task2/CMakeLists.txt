cmake_minimum_required(VERSION 3.2)
add_compile_options(-lm)

project(labs LANGUAGES C)


add_executable(lab2 lab2.c enums.h)

add_library(mylib STATIC func.c)


target_link_libraries(lab2 PUBLIC mylib)


