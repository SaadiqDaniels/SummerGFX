cmake_minimum_required(VERSION 3.10)
project(SummerGFX VERSION 0.0.1)

# This prooject will target the C++17 standard
set(CMAKE_CXX_STANDARD 17)

# Common compilation options to reduce bugs in code
set(GLOBAL_CXX_COMPILE_OPTIONS
        -Wall -Werror -Wextra -pedantic)

# The standard graphics library interface
add_subdirectory(Standard)

# Make sure to define -DGFX_TYPE as either OpenGL, Vulkan, DirectX12, or DirectX9
if (GFX_TYPE STREQUAL "OpenGL")
    message(STATUS "OpenGL chosen as graphics library")
    add_subdirectory(OpenGL)
elseif(GFX_TYPE STREQUAL "Vulkan")
    message(STATUS "Vulkan chosen as graphics library")
elseif(GFX_TYPE STREQUAL "DirectX12")
    message(STATUS "DirectX12 chosen as graphics library")
else()
    message(STATUS "DirectX9 chosen as graphics library")
endif()

# The cpu-side data storage functions for a graphics library
add_subdirectory(GfxStorage)

# The unit tests for the graphics library
add_subdirectory(UnitTests)

# Demo programs for the graphics library
add_subdirectory(Demo)
