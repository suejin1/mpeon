cmake_minimum_required(VERSION 3.10)
project(test)

add_subdirectory(lib)

add_executable(program main.cc)
target_include_directories(includes)
target_link_libraries(program shape)
