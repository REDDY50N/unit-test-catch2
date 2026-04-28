cmake_minimum_required(VERSION 3.15...3.36)

project(war-zone
        VERSION 0.0.1
        DESCRIPTION "Unit Testing of a fictional war zone"
        LANGUAGES CXX)

# -----------------------------------------------
# COMPILER CONFIGURATION
# -----------------------------------------------
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Let's ensure -std=c++xx instead of -std=g++xx
set(CMAKE_CXX_EXTENSIONS OFF)

# HINT: Turn ON to fix compiler warnings (Only supported in CMake >= 3.24)
set(CMAKE_COMPILE_WARNING_AS_ERROR OFF)

# -----------------------------------------------
# CMAKE PACKAGE MANAGER (CPM
# -----------------------------------------------
include(cmake/CPM.cmake)
CPMAddPackage(NAME Catch2    GIT_REPOSITORY "https://github.com/catchorg/Catch2.git"   GIT_TAG "v3.8.1")

# -----------------------------------------------
# UNIT TESTING
# -----------------------------------------------
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
enable_testing()


# -----------------------------------------------
# PROJECT CONFIGURATION
# -----------------------------------------------
set(EXEC_NAME ${PROJECT_NAME})

# bin dir: https://stackoverflow.com/questions/6594796/how-do-i-make-cmake-output-into-a-bin-dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(src)
add_subdirectory(tests)
