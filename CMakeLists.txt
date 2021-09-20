cmake_minimum_required(VERSION 3.17)
project(fish_feeder)

set(CMAKE_CXX_STANDARD 20)

add_executable(fish_feeder main.cpp)
target_link_libraries(fish_feeder -lOpenGL32 -lfreeGLUT)