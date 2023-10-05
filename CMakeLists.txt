cmake_minimum_required(VERSION 3.23)
project(gyak1)

set(CMAKE_CXX_STANDARD 23)

add_executable(gyak1 main.cpp)

include_directories(functions.cpp functions.h)

