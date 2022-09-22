cmake_minimum_required(VERSION 3.15)
project(PrepLab7)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PrepLab7
        ItemToPurchase.cpp
        ItemToPurchase.h
        main.cpp)
