# ---------------------------------------------------------------------------
# Unit tests, using GoogleTest
# ---------------------------------------------------------------------------
include(FetchContent)

# Download a fixed version of GoogleTest, so every machine builds the same thing
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
  SYSTEM   # our strict warnings shouldn't apply to GoogleTest's own code
)
FetchContent_MakeAvailable(googletest)

# The test program
add_executable(unit_tests
  unit/core/flag_test.cpp
  # add each new test file here
)

target_link_libraries(unit_tests PRIVATE
  flagtuner_lib        # the code being tested
  flagtuner_options    # strict warnings for the tests too
  GTest::gtest_main)   # GoogleTest, plus a ready-made main()

# Register each TEST with ctest
include(GoogleTest)
gtest_discover_tests(unit_tests)
