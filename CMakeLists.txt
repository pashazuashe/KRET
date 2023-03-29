cmake_minimum_required(VERSION 3.22.1)

project(KRET C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(KRET)
add_subdirectory(googletest)
add_subdirectory(test)

enable_testing()