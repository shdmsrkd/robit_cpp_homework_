cmake_minimum_required(VERSION 3.5)

project(HW_001 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(HW_001 main.cpp Stack.h stack.cpp Queue.h queue.cpp)
