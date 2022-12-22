cmake_minimum_required(VERSION 3.10)
project(cmake_test)

add_subdirectory(lib)

add_executable (program main.cc)

target_link_libraries(program shape)