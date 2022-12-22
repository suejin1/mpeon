#cmake버전 설정
cmake_minimum_required(VERSION 3.10)
#현재 프로젝트의 이름 설정
project(cmake_test)


add_subdirectory(lib)

#main.cc를 이용해서 filename : program을 빌드한다
add_executable(program main.cc)

#filename : program 바이너리가 요구하는 바이너리 shpae을 추가한다
target_link_libraries(program shape)