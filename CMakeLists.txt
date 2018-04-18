cmake_minimum_required(VERSION 3.8)
project(sorting-implementation)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp main.h tree/RbTree.cpp tree/RbTree.h)
add_executable(sorting-implementation ${SOURCE_FILES} tree/RbTree.cpp tree/RbTree.h)