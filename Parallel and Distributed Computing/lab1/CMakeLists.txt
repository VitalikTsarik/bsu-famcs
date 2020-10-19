cmake_minimum_required(VERSION 3.16)
project(lab1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
include(ExternalProject)
ExternalProject_Add(googletest
        GIT_REPOSITORY    https://github.com/google/googletest.git
        GIT_TAG           master
        SOURCE_DIR        "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
        BINARY_DIR        "${CMAKE_CURRENT_BINARY_DIR}/googletest-build"
        CONFIGURE_COMMAND ""
        BUILD_COMMAND     ""
        INSTALL_COMMAND   ""
        TEST_COMMAND      ""
        )
enable_testing()

add_executable(runUnitTests src/tests/multiplication_test.cpp src/matrix_multiplication.h src/matrix_multiplication.cpp src/utils.h src/utils.cpp)
target_link_libraries(runUnitTests gtest gtest_main)
add_test(runUnitTests runUnitTests)

add_executable(lab1 src/main.cpp src/matrix_multiplication.h src/utils.h src/utils.cpp src/matrix_multiplication.cpp)