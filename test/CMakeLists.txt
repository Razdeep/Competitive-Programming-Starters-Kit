include(CodeCoverage)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

file(GLOB_RECURSE SOURCES "../src/*.cpp")
file(GLOB_RECURSE TEST_SOURCES "*.cpp")

add_executable(cpskTest ${TEST_SOURCES} ${SOURCES})

target_link_libraries(cpskTest gtest gtest_main pthread)

add_test(NAME cpskTest
        COMMAND cpskTest)

setup_target_for_coverage_lcov(
                            NAME cpskTestCoverage
                            EXECUTABLE cpskTest)

gtest_discover_tests(cpskTest)