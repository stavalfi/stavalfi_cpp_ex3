cmake_minimum_required(VERSION 3.9)
project(stavalfi_cpp_ex3)

set(CMAKE_CXX_STANDARD 11)
if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fno-elide-constructors -Wall -Wvla -Werror")  # -Wextra is too much
endif()

add_executable(stavalfi_cpp_ex3 main.cpp)