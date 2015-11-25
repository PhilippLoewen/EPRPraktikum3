cmake_minimum_required(VERSION 3.3)
project(Praktikum3)

set(CMAKE_CFLAGS "${CMAKE_C_FLAGS} -Wall -std=c11 -pedantic")

set(SOURCE_FILES main.c)
add_executable(Praktikum3 ${SOURCE_FILES})