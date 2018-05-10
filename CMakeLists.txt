cmake_minimum_required(VERSION 3.5.1)
project(sorting-implementation)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp main.h tree/RbTree.cpp tree/RbTree.h tree/Heap.cpp tree/Heap.h)
add_executable(sorting-implementation ${SOURCE_FILES} main.cpp main.h)