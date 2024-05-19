cmake_minimum_required(VERSION 3.0)
project(NoLibC)

# Set compiler options
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -fPIE -w")

# Define the 'NoLibC' library target
add_library(NoLibC example.c)

# Define the 'example' target and associate it with the 'example.c' source file
add_executable(example example.c)

# Indicate that 'example' depends on 'NoLibC'
target_link_libraries(example NoLibC)

# Add directory containing header files for 'NoLibC' library
target_include_directories(NoLibC PUBLIC src/)