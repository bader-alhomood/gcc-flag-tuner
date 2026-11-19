# ---------------------------------------------------------------------------
# gcc-flag-tuner: top-level build file
# ---------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.25)

project(flagtuner
  VERSION 0.1.0
  LANGUAGES CXX)

# ---- C++ standard ----------------------------------------------------------
set(CMAKE_CXX_STANDARD 20)            # use C++20
set(CMAKE_CXX_STANDARD_REQUIRED ON)   # fail if the compiler can't do C++20
set(CMAKE_CXX_EXTENSIONS OFF)         # standard C++ only, no gcc-only extras
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # lets VS Code match the real build

# ---- Shared warning settings ----------------------------------------------
# An INTERFACE library holds no code, only settings.
# Anything that links to it gets these warnings.
add_library(flagtuner_options INTERFACE)
target_compile_options(flagtuner_options INTERFACE
  -Wall        # common mistakes
  -Wextra      # more common mistakes
  -Wpedantic   # anything that isn't strictly standard C++
  -Wshadow     # a variable hiding another with the same name
  -Wconversion # silent number conversions that can lose data
  -Werror)     # treat every warning as an error

# ---- Sub-folders -----------------------------------------------------------
add_subdirectory(src)

# ---- Tests -----------------------------------------------------------------
enable_testing()
add_subdirectory(tests)