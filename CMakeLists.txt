# CMakeLists.txt
# 
# This file is part of the RawC project.
#
# Author: ruxixa
#
# Date: 20.05.2024

cmake_minimum_required(VERSION 3.0)

project(RawC)

# Flags used:
# -fPIE: Generate position-independent code
# -w: Disable all warnings
#
# The reason I had to disable warnings
# is because the compiler would complain
# about things such as no return main function,
# what is intender because we are using 
# own exit() implementation
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIE -w")

# Add the source files
target_link_libraries(example RawC)
target_include_directories(RawC PUBLIC src/)