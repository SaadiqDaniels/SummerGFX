cmake_minimum_required(VERSION 3.10)
PROJECT(OpenGL VERSION 0.0.0 LANGUAGES CXX)

# The source files for the opengl graphics library
set(GFX_SOURCES
)

# Creating the library itself
add_library(GFX STATIC ${GFX_SOURCES})

# The library will define OpenGL for all linked targets, so if there is any opengl specific code it will be turned on / off
target_compile_definitions(GFX PUBLIC OPENGL)

# Adding the regular compilation options to the opengl library
target_compile_options(GFX PRIVATE
        ${GLOBAL_CXX_COMPILE_OPTIONS})

# Linking to the standard headers in the shared folder
target_link_libraries(GFX PRIVATE Standard)

# Anything that uses this library will be using the sources folder in their include paths
target_include_directories(GFX PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")