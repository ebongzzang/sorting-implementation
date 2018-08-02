cmake_minimum_required(VERSION 3.5.1)
project(sorting-implementation)

set(CMAKE_CXX_STANDARD 14)


set(SOURCE_FILES main.cpp main.h tree/RbTree.cpp tree/RbTree.h sorting/MergeSort.cpp sorting/MergeSort.h tree/Heap.h tree/Heap.cpp
        sorting/BasicSort.cpp sorting/BasicSort.h sorting/BasicSort.cpp sorting/BasicSort.h sorting/Quicksort.cpp sorting/Quicksort.h
        graph/GraphSearch.cpp graph/GraphSearch.h graph/Graph.cpp graph/Graph.h graph/GraphUnitTest.cpp lib/catch.hpp)


add_executable(sorting-implementation ${SOURCE_FILES} main.cpp main.h graph/GraphUnitTest.cpp)