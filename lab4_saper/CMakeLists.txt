cmake_minimum_required(VERSION 3.10)

project (exec)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -g")
include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
)
add_library(bib src/play.cpp)
add_executable(exec src/play.cpp src/vector.cpp src/matrix.cpp src/sapper.cpp )

target_link_libraries(exec bib)
add_compile_options(${CMAKE_CXX_FLAGS})
add_custom_target(run ./exec)
add_custom_target(valgrind valgrind --tool=memcheck ./exec) 
