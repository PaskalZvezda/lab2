cmake_minimum_required(VERSION 3.10.0)
project(lab2 VERSION 0.1.0 LANGUAGES C CXX)

add_library(lab2 ip_filter.cpp)

include(CTest)
enable_testing()

