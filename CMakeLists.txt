cmake_minimum_required(VERSION 3.12)
project(Complex)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(googletest/googletest)

set(COVERAGE OFF CACHE BOOL "Coverage")

include_directories(googletest/googletest/include)
set(SOURCE_FILES main.cpp complex.cpp complex.h)
add_executable(Complex ${SOURCE_FILES})
target_link_libraries(Complex gtest gtest_main)

if (COVERAGE)
    target_compile_options(tests PRIVATE --coverage)
    target_link_libraries(tests PRIVATE --coverage)
endif()