cmake_minimum_required(VERSION 2.8)

project(xv)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories("/home/qabuilder/gitsrc/sdk/apps/roadrunner/avtrace")

add_library(avtrace_preload SHARED avtrace_preload.cpp)
target_link_libraries(avtrace_preload dl)
