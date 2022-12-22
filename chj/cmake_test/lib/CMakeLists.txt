# /lib/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(cmake_test)

# 정적 라이브러리 shape 를 만든다.
add_library(shape STATIC shape.cc)

# 해당 라이브러리 컴파일 시 사용할 헤더파일 경로
target_include_directories(shape PUBLIC ${CMAKE_SOURCE_DIR}/includes)

#라이브러리를 컴파일 할 옵션을 지정해준다
target_compile_options(shape PRIVATE -Wall -Werror)

#shape바이너리가 요구하는 바이너리 PRIVATE : pthread를 추가한다
target_link_libraries(shape PRIVATE pthread)