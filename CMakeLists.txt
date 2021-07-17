cmake_minimum_required(VERSION 3.0.0)
project(sort_string VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(a           a.c)
add_executable(test_bed    test_bed.cpp)
add_executable(sort_string sort_string.cpp)
add_executable(linear_list linear_list.cpp)
add_executable(link_list   link_list.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
