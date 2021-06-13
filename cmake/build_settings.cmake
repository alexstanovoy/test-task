set(SOURCES "src")
add_compile_options("-Wall" "-Wextra" "-pedantic" "-Werror" "-O0" "-g" "--coverage")
#add_link_options("-lgcov" "--coverage")  # No add_link_options in Xenial! Sad

include_directories(${SOURCES})
