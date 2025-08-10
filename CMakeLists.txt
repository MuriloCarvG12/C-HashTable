cmake_minimum_required(VERSION 3.27)
project(HashTables C)

set(CMAKE_C_STANDARD 11)

add_executable(HashTables main.c
        hash_table.c
        hash_table.h)
