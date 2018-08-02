cmake_minimum_required(VERSION 3.5.1)
project(sorting-implementation)

set(CMAKE_CXX_STANDARD 14)


set(GRAPH graph/GraphSearch.cpp graph/GraphSearch.h graph/Graph.cpp graph/Graph.h graph/undirectional/UndirectedGraph.cpp graph/undirectional/UndirectedGraph.h)

set(SOURCE_FILES tree/RbTree.cpp tree/RbTree.h sorting/MergeSort.cpp sorting/MergeSort.h tree/Heap.h tree/Heap.cpp
        sorting/BasicSort.cpp sorting/BasicSort.h sorting/Quicksort.cpp sorting/Quicksort.h graph/undirectional/UndirectedGraph.cpp graph/undirectional/UndirectedGraph.h)

add_executable(sorting-implementation ${SOURCE_FILES} ${GRAPH} main.cpp main.h)

add_library(CatchMain OBJECT lib/catch.hpp)

add_executable(graphTest ${GRAPH} graph/GraphTestRunner.cpp graph/GraphUnitTest.cpp lib/catch.hpp graph/undirectional/UndirectedGraph.cpp graph/undirectional/UndirectedGraph.h)