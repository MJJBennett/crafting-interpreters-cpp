cmake_minimum_required(VERSION 3.3)
project(Interpreter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Note:
# This is used with YCM to allow the clang engine to automatically compile in the background
# and allow for autocomplete. For this to work properly, it's necessary to create a symlink
# to compile_commands.json from the root directory of the project.
# This can be done using `ln -s output/compile_commands.json compile_commands.json`
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(Interpreter src/app.cpp src/Interpreter.cpp)

target_include_directories(Interpreter PRIVATE "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>")
