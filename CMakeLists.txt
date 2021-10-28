if (NOT DEFINED CMAKE_INSTALL_PREFIX)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Installation Directory")
endif()
message(STATUS "CMAKE_INSTALL_PREFIX  = ${CMAKE_INSTALL_PREFIX}")

cmake_minimum_required(VERSION 3.15)

project(Hello)

option(HELLO_COVERAGE "code coverage?" OFF)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(INSERT CMAKE_MODULE_PATH 0 "${CMAKE_SOURCE_DIR}/cmake/modules")
find_package(GTest REQUIRED)

message("GTest include path: ${GTEST_INCLUDE_DIR}")
message("GTest lib path: ${GTEST_LIBRARY}")

add_library(hello STATIC
    src/Hello.cpp
)

set_target_properties(hello PROPERTIES
    PUBLIC_HEADER "include/Hello.h"
)

target_include_directories(hello PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

if(HELLO_COVERAGE)
    message(STATUS ">>> test coverage: YES")
    target_compile_options(hello PUBLIC -coverage -fprofile-arcs -ftest-coverage)
    target_link_libraries(hello PUBLIC -coverage -lgcov)
endif()

enable_testing()

macro(hello_add_test name)
    message("test name: ${name}")
    add_executable(test_${name} test/test_${name}.cpp)
    target_link_libraries(test_${name} PRIVATE hello GTest::GTest)
    gtest_add_tests(TARGET test_${name})
endmacro()

hello_add_test(hello)

if(HELLO_COVERAGE)
  # first run `make test` or `ctest`, ensure .gcdata generated
  # then run `make test_coverage` to get statistics
  # if `make test_coverage` failed, most likely no `make test` executed yet.
  add_custom_target(test_coverage
    COMMAND lcov -d ./ -c -o lcov.info
    COMMAND lcov -r lcov.info '/usr/*' -o lcov.info
    COMMAND lcov -r lcov.info '*/build/*' -o lcov.info
    COMMAND lcov -r lcov.info '*/test/test_*' -o lcov.info
    COMMAND lcov --list lcov.info
    COMMAND genhtml -o coverage_report lcov.info
    COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "View test coverage html report:"
    COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "    cd coverage_report"
    COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "    python -m http.server 7082"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  )
endif()

#----------------------------------------------------------------------
# Installing
#----------------------------------------------------------------------
install(TARGETS hello
  ARCHIVE DESTINATION lib
  PUBLIC_HEADER DESTINATION include/hello
)

# 还没学会，先抄着
# configure_file(${CMAKE_SOURCE_DIR}/cmake/helloConfig.cmake.in helloConfig.cmake @ONLY)
# install(FILES
#   ${CMAKE_BINARY_DIR}/helloConfig.cmake
#   ${CMAKE_SOURCE_DIR}/README.md
#   ${CMAKE_SOURCE_DIR}/LICENSE
#   DESTINATION "."
# )

# # please make sure example directory does not contain `build` sub directory
# install(DIRECTORY
#   "${PROJECT_SOURCE_DIR}/example/" DESTINATION "example"
# )

# set(CPACK_GENERATOR "ZIP")
# set(CPACK_PACKAGE_FILE_NAME "HelloCpp-Linux-x64")
# include(CPack)