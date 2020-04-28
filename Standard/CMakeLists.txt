cmake_minimum_required(VERSION 3.10)
PROJECT(Standard VERSION 0.0.1 LANGUAGES CXX)

# Add the SDL2 cmake file to the module path
#list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LISAT_DIR}/SDL2CMake")
# Find the SDL2 package
#find_package(SDL2 REQUIRED)

set(STANDARD_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/gfx.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/defines.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/exception.h"
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

# Add the source files as source files for this library
target_sources(Standard INTERFACE ${STANDARD_SOURCES})
# This define allows the defined graphics classes to be inherited from and have functionality extended by derived classes
target_compile_definitions(Standard INTERFACE GRAPHICS_BASE_CLASSES)
# Include this source folder and SDL2 source folders as necessary for this library
#target_include_directories(Standard INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/src" ${SDL2_INCLUDE_DIRS})
target_include_directories(Standard INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/src" ${SDL2_INCLUDE_DIRS})
# Link the SDL2 library
target_link_libraries(Standard INTERFACE glm_static)
