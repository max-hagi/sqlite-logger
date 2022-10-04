cmake_minimum_required(VERSION 3.23)
project(Assignment_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment_1 generator.cpp Logger.cpp headers.h LogMessage.cpp Logger.h LogMessage.h dumper.cpp)
