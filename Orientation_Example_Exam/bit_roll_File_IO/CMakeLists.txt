cmake_minimum_required(VERSION 3.13)
project(bit_roll_File_IO C)

set(CMAKE_C_STANDARD 99)

add_executable(bit_roll_File_IO main.c bit_roll.h bit_roll.c)