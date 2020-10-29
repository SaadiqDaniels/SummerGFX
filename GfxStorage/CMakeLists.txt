cmake_minimum_required(VERSION 3.10)
PROJECT(Storage VERSION 0.0.0)

add_library(ShaderUtils STATIC src/shader_utils.h src/shader_utils.cpp)
target_include_directories(ShaderUtils PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")