cmake_minimum_required(VERSION 3.9)
project(stavalfi_cpp_ex3) # name of the project

set(CMAKE_CXX_STANDARD 11) # c++ version

include_directories(include) # include all header files under directory "include" so we can use them

if (CMAKE_COMPILER_IS_GNUCC) # add more flags to gcc for safer builds
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-elide-constructors -Wall -Werror -Wvla")  # -Wextra is too much
endif ()

file(GLOB MY_CPP_FILES src/*.cpp main.cpp) # include all cpp files under directory "src"
add_executable(stavalfi_cpp_ex3 ${MY_CPP_FILES}) # create executable
