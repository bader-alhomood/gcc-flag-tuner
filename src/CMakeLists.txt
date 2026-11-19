# ---------------------------------------------------------------------------
# flagtuner_lib: all of the tool's logic.
# The tests and (later) the command-line app both use this library.
# ---------------------------------------------------------------------------
add_library(flagtuner_lib
  core/flag.cpp
  # add each new .cpp file here
)

# Code using this library can #include "flagtuner/..." headers
target_include_directories(flagtuner_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Apply the strict warnings to this library
target_link_libraries(flagtuner_lib PRIVATE flagtuner_options)