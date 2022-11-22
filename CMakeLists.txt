cmake_minimum_required(VERSION 3.20)
project(GOL LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set( SRC_FILES src/run.cpp src/zell.cpp)

add_executable(gol ${SRC_FILES})