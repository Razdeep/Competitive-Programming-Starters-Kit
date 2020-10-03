enable_testing()

file(GLOB_RECURSE SOURCES "../src/*.cpp")
file(GLOB_RECURSE TEST_SOURCES "*.cpp")

add_executable(runTest ${TEST_SOURCES} ${SOURCES})

target_link_libraries(runTest gtest gtest_main pthread)

add_test(NAME runTest
        COMMAND runTest)