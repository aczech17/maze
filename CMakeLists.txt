cmake_minimum_required(VERSION 3.24)
project(maze)

set(CMAKE_CXX_STANDARD 17)

add_executable(maze main.cpp graph.cpp maze.cpp cell_array.cpp)
