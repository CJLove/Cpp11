CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

project(CPP11)

set(BUILD_64BIT OFF CACHE BOOL "Build 64-bit executables")

add_definitions(-std=c++11)
if(BUILD_64BIT)
    add_definitions(-m64)
endif()

add_subdirectory(Auto)
