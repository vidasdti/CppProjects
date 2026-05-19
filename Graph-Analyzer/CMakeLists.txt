cmake_minimum_required(VERSION 3.10)

project(SmartGraphAnalyzer)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(
    SmartGraphAnalyzer

    src/main.cpp
    src/Graph.cpp
    src/Algorithms.cpp
    src/FileManager.cpp
    src/Utilities.cpp
)