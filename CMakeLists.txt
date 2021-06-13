cmake_minimum_required(VERSION 3.9)
set(PROJECT_REVISION "0.0.1")
project(qapp_test VERSION ${PROJECT_REVISION})

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
  message(WARNING "Do not build in-source. Please remove CMake cache, then build out-of-source.")
endif()

include("cmake/build_settings.cmake")
include("cmake/codecov_settings.cmake")

add_library(logger_lib STATIC src/logger.c)
target_link_options(logger_lib PRIVATE "-lgcov" "--coverage")  # Travis uses Xenial so we need it

include("tests/CMakeLists.txt")
