cmake_minimum_required(VERSION 3.13)
project(old_enough C)

set(CMAKE_C_STANDARD 99)

add_executable(old_enough main.c oldenough.h oldenough.c)