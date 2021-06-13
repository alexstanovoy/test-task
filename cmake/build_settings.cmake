set(SOURCES "src")
add_compile_options("-Wall" "-Wextra" "-pedantic" "-Werror" "-O0" "-g" "--coverage" "-lgcov" "--coverage")
add_link_options("-lgcov" "--coverage")

include_directories(${SOURCES})
