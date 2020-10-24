cmake_minimum_required(VERSION 3.10)

project(opengl-test)

# set the output directory
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/bin)

# set compilation mode
set(CMAKE_BUILD_TYPE Debug)

find_package(OpenGL REQUIRED)

# glew library
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

# GLFW library
find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})

add_subdirectory(src)