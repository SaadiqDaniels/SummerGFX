cmake_minimum_required(VERSION 3.10)
PROJECT(OpenGL VERSION 0.0.0 LANGUAGES CXX)

#Find the opengl package from the user's computer
find_package(OpenGL REQUIRED)

#Find the glew package from the user's computer
find_package(GLEW REQUIRED)

# The source files for the opengl graphics library
set(GFX_SOURCES
        src/extended_gfx.h
        src/extended_gfx.cpp
        src/standard_interface.cpp
        src/standard_mesh.cpp
        src/standard_shader.cpp
)

# Creating the library itself
add_library(GFX STATIC ${GFX_SOURCES})

# The library will define OpenGL for all linked targets, so if there is any opengl specific code it will be turned on / off
target_compile_definitions(GFX PUBLIC OPENGL)

# Adding the regular compilation options to the opengl library
target_compile_options(GFX PRIVATE
        ${GLOBAL_CXX_COMPILE_OPTIONS})

# Anything that uses this library will be using the sources folder in their include paths
target_include_directories(GFX PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Include the GLEW directories privately
target_include_directories(GFX PRIVATE ${GLEW_INCLUDE_DIRS})

# Linking to the standard headers in the shared folder
target_link_libraries(GFX PUBLIC Standard ${GLEW_LIBRARIES} OpenGL::OpenGL)
