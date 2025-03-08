cmake_minimum_required(VERSION 3.27)
project(eastwood CXX)
set(CMAKE_CXX_STANDARD 20)

add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/MP>)

add_subdirectory("eastwood")