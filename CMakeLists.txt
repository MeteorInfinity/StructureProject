cmake_minimum_required(VERSION 3.7)
project(StructureProject)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c _Graph.h Graph.c _Quene.h Quene.c _Stack.h Stack.c Tree/_Set.h Tree/Set.c Stack.c _Stack.h Tree/_Heap.h Tree/Heap.c Tree/Huffman.c Search.c Sort.c)
add_executable(StructureProject ${SOURCE_FILES})