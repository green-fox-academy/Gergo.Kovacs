cmake_minimum_required(VERSION 3.13)
project(patrolstation)

set(CMAKE_CXX_STANDARD 14)

add_executable(patrolstation main.cpp Car.cpp Car.h Station.cpp Station.h)