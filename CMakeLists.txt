cmake_minimum_required(VERSION 3.16)
project(MA4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fopenmp")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_COMPILER "/opt/homebrew/bin/g++-14")  

add_executable(MA4 main.cpp)
