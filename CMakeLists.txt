cmake_minimum_required(VERSION 3.17)
project(cplus)
set( CMAKE_BUILD_TYPE Debug )
set(CMAKE_CXX_STANDARD 14)


add_executable(
        cplus partIII/src/p11.cpp
)