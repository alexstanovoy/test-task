cmake_minimum_required(VERSION 3.9)
set(PROJECT_REVISION "0.0.1")
project(qapp_test VERSION ${PROJECT_REVISION})

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
  message(WARNING "Do not build in-source. Please remove CMake cache, then build out-of-source.")
endif()

add_library(logger_lib STATIC src/logger.c)

include("cmake/build_settings.cmake")
include("cmake/codecov_settings.cmake")

# finalize
set(CMAKE_C_FLAGS               ${CXX_COMPILER_FLAGS})
set(CMAKE_EXE_LINKER_FLAGS      ${CXX_LINKER_FLAGS})

include("tests/CMakeLists.txt")
