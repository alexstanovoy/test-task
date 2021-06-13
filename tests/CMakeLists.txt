include(CTest)
enable_testing()

file(GLOB TESTS "${TESTS_DIR}/*.c")
foreach(test ${TESTS})
  get_filename_component(bare_name ${test} NAME_WE)
  add_executable(${bare_name} "${test}")
  target_link_libraries(${bare_name} logger_lib)
  target_link_options(${bare_name} PRIVATE "-lgcov" "--coverage")  # Travis uses Xenial so we need it
  add_test(${bare_name} "./${bare_name}")
endforeach()
