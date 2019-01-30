cmake_minimum_required(VERSION 3.13)
project(fleetofthing)

set(CMAKE_CXX_STANDARD 14)

add_executable(fleetofthing main.cpp thing.cpp thing.h fleet.cpp fleet.h)