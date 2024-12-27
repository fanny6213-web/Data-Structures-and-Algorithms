cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(LinkedList VERSION 1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(LinkedList main.cpp ${SRC_FILES})

target_include_directories(LinkedList PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#For exporting symbols for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
