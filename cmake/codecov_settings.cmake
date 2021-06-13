set(TESTS_DIR                   "tests/tests_src")
set(GCOV_NAME                   "gcov")
set(C_COMPILER_FLAGS            "${C_COMPILER_FLAGS} -g --coverage")
set(С_LINKER_FLAGS              "${C_LINKER_FLAGS} -lgcov --coverage")

find_program(CTEST_COVERAGE_COMMAND NAMES "${GCOV_NAME}")
if(NOT CTEST_COVERAGE_COMMAND)
  message(FATAL_ERROR "There is no gcov. Please, install it before testing.")
endif()
