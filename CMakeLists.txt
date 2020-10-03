cmake_minimum_required(VERSION 3.0)
project(cpsk)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
include_directories(core/exceptions)
file(GLOB_RECURSE sources "src/*.cpp")

file(MAKE_DIRECTORY ~/.cpsk)
file(COPY TEMPLATE
        DESTINATION $ENV{HOME}/.cpsk)

add_executable(cpsk main.cpp ${sources})

IF(BUILD_TESTS)
    add_subdirectory(test)
ENDIF()

install(TARGETS cpsk
        DESTINATION bin)