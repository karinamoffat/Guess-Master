cmake_minimum_required(VERSION 3.23)
project(trees C)

set(CMAKE_C_STANDARD 99)

add_executable(trees postOrderTraversal.c
        mergeBST.c
        BSTToAVL.c)
