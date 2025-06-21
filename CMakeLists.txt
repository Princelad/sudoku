cmake_minimum_required(VERSION 3.10.0)
project(sudoku VERSION 0.1.0 LANGUAGES C CXX)

# Find raylib package from system installation
find_package(raylib REQUIRED)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Source files
file(GLOB_RECURSE SOURCES 
    "src/*.cpp"
    "main.cpp"
)

# Create executable
add_executable(sudoku ${SOURCES})
target_link_libraries(sudoku PRIVATE raylib)

