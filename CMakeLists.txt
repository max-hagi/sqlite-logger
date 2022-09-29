cmake_minimum_required(VERSION 3.23)
project(Assignment_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment_1 generator.cpp logger.cpp headers.h log_message.cpp logger.h dumper.cpp log_messages.h)
