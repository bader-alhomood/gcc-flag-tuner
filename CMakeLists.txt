cmake_minimum_required(VERSION 3.25)

project(flagtuner
  VERSION 0.1.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Strict warnings, shared by everything we build
add_library(flagtuner_options INTERFACE)
target_compile_options(flagtuner_options INTERFACE
  -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Werror)

add_subdirectory(src)