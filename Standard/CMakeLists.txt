cmake_minimum_required(VERSION 3.10)
PROJECT(Standard VERSION 0.0.1 LANGUAGES CXX)

set(STANDARD_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/gfx.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/defines.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/interface.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/camera.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/font.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/mesh.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/namedbuffer.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/renderable.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/shader.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/texture.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/viewport.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/window.h"
        )

add_library(Standard INTERFACE)

target_sources(Standard INTERFACE ${STANDARD_SOURCES})
target_include_directories(Standard INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/src")