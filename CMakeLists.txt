cmake_minimum_required(VERSION 3.20)
project(Chip8Emulator C) # Explicitly set as a C project

# Use C99 or C11 standard
set(CMAKE_C_STANDARD 23)

# Define the path to your local SDL2 folder
set(SDL2_DIR ${CMAKE_SOURCE_DIR}/SDL2)

# Tell CMake where to find SDL2 headers
include_directories(${SDL2_DIR}/include/SDL2)

# Tell CMake where to find the pre-compiled libraries
link_directories(${SDL2_DIR}/lib)

add_executable(Chip8Emulator main.c)

# Link the executable against MinGW and SDL2
target_link_libraries(Chip8Emulator mingw32 SDL2main SDL2)