cmake_minimum_required(VERSION 3.0)
project(cpsk)

option(BUILD_TESTS "Builds test and code coverage" ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

include_directories(include)
file(GLOB_RECURSE sources "src/*.cpp")

file(MAKE_DIRECTORY ~/.cpsk)
file(COPY TEMPLATE
        DESTINATION $ENV{HOME}/.cpsk)

add_executable(cpsk main.cpp ${sources})

IF(BUILD_TESTS)
    message("BUILD_TESTS: ON")
    enable_testing()
    set(CMAKE_BUILD_TYPE "DEBUG")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -fprofile-arcs -ftest-coverage")
    add_subdirectory(test)
ELSE()
    message("BUILD_TESTS: OFF")
    set(CMAKE_BUILD_TYPE "RELEASE")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
ENDIF()

install(TARGETS cpsk
        DESTINATION bin)