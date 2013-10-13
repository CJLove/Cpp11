CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)

project(CPP11)

set(BUILD_64BIT OFF CACHE BOOL "Build 64-bit executables")

include_directories("./include")

add_definitions(-std=c++11)
if(BUILD_64BIT)
    add_definitions(-m64)
endif()

if(BUILD_CLANG_LIBCPP)
    add_definitions(-stdlib=libc++ )
    set( CMAKE_EXE_LINKER_FLAGS "-std=c++11 -stdlib=libc++" )
endif()

add_subdirectory(Auto)
add_subdirectory(SmartPtrs)
add_subdirectory(Strings)
add_subdirectory(Threads)
add_subdirectory(Structures)
add_subdirectory(Move)
add_subdirectory(Variadic)
