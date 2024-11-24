cmake_minimum_required(VERSION 3.4...3.18)
project(pyatium LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PYBIND11_FINDPYTHON ON)

find_package(Python 3.13 COMPONENTS Interpreter Development REQUIRED)
add_subdirectory(extern/pybind11)

include_directories(${PROJECT_SOURCE_DIR}/include)

pybind11_add_module(pyatium src/bindings.cpp src/neural_network.cpp)