cmake_minimum_required(VERSION 3.10)
PROJECT(Standard VERSION 0.0.1 LANGUAGES CXX)

set(STANDARD_SOURCES
        )

add_library(Standard INTERFACE)

target_sources(Standard INTERFACE ${STANDARD_SOURCES})
target_include_directories(Standard INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/src")