cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(BinarySearchTree VERSION 1.0)

file(GLOB_RECURSE SRC_FILES src/*.tpp)
list(FILTER SOURCES EXCLUDE REGEX "src/*.cpp")
message("Source directory: ${CMAKE_CURRENT_SOURCE_DIR}")
message("Source files: ${SRC_FILES}")
message("Ignored files: ${CMAKE_INGORE_PATH}")

add_executable(BinarySearchTree main.cpp ${SRC_FILES})

target_include_directories(BinarySearchTree PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CMKAE_EXPORT_COMPILE_COMMANDS ON)
