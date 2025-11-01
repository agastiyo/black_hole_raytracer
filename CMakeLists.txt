cmake_minimum_required(VERSION 3.15)

project(black_hole_raytracer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project directories
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

# Collect sources (only .cpp/.c files). Header-only code in src/classes is included via include directories.
file(GLOB_RECURSE PROJECT_SOURCES
    "${SRC_DIR}/*.cpp"
    "${SRC_DIR}/*.c"
)

if (PROJECT_SOURCES)
    add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
else()
    message(FATAL_ERROR "No source files found in ${SRC_DIR}. Expected at least src/main.cpp")
endif()

target_include_directories(${PROJECT_NAME} PRIVATE
    ${SRC_DIR}
    ${SRC_DIR}/classes
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Convenience options
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
endif()

option(BUILD_TESTING "Build tests" OFF)

message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "Source dir: ${SRC_DIR}")