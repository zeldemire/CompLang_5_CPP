cmake_minimum_required(VERSION 3.7)
project(CPP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES myset.h myset.cpp)
add_executable(CPP ${SOURCE_FILES})