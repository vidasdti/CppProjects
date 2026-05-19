cmake_minimum_required(VERSION 3.10)

project(MatrixAlgebraEngine)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(
    MatrixEngine
    examples/example.cpp
)