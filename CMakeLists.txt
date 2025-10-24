# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(auxv C)

set(CMAKE_C_STANDARD 11)

# Debug flags
set(CMAKE_C_FLAGS_DEBUG "-g -O0 -DDEBUG")

# Release flags
set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG -Wall -Wextra -Wpedantic -Werror")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(hwcap main.c hwcap.c)
