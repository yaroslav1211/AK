cmake_minimum_required(VERSION 3.10)
project(calculator_project)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)

# Create static library
add_library(calc STATIC calculator.cpp)

# Create executable
add_executable(main main.cpp)
target_link_libraries(main calc)
