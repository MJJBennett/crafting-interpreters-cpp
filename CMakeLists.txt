cmake_minimum_required(VERSION 3.3)
project(Interpreter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(Interpreter src/app.cpp)

target_include_directories(Interpreter PRIVATE "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>")
