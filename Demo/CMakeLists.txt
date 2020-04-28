cmake_minimum_required(VERSION 3.10)
project(DemoProjects VERSION 0.0.1)

find_package(SDL2 REQUIRED)

add_executable(rotating_triangle src/rotating_triangle.cpp)
target_include_directories(rotating_triangle PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(rotating_triangle PRIVATE GFX ${SDL2_LIBRARIES})