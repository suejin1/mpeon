#정적 라이브러리 shape를 만드는 코드
add_library(shape STATIC shape.cc)

#shape라이브러리 컴파일시 사용할 헤더파일(foo) 경로
target_include_directories(shape PUBLIC ${CMAKE_SOURCE_DIR}/includes)

#해당 라이브러리를 컴파일 할 옵션
target_compile_options(shape PRIVATE -Wall -Werror)

target_link_libraries(shape PRIVATE pthread)
