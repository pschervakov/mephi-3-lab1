cmake_minimum_required(VERSION 3.17)
project(mephi_3_lab1)

set(CMAKE_CXX_STANDARD 14)
add_executable(mephi_3_lab1
        menu.cpp)

target_link_libraries(mephi_3_lab1 gtest gtest_main)

