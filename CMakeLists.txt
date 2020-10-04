# cmake_minimum_required(VERSION <specify CMake version here>)
project(mephi-3-lab1)

set(CMAKE_CXX_STANDARD 14)

add_executable(mephi-3-lab1 tests.cpp)
target_link_libraries(mephi-3-lab1 gtest gtest_main)