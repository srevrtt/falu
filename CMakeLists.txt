cmake_minimum_required(VERSION 3.0)
project(falu VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(SRCS src/lexer.cpp src/main.cpp src/util.cpp)

add_executable(falu ${SRCS})
