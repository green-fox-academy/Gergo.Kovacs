cmake_minimum_required(VERSION 3.13)
project(materialrew_)

set(CMAKE_CXX_STANDARD 14)

add_executable(materialrew_ main.cpp shape.cpp shape.h Rect.cpp Rect.h Circle.cpp Circle.h)