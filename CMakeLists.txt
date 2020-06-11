cmake_minimum_required(VERSION 3.12)
project(xplatform_ci_evaluation VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup(TARGETS)
else()
    message(WARNING "conanbuildinfo.cmake doesn't exist, you need to run `conan install ..`")
endif()

# Conan generates FindPackage.cmake files here
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_CURRENT_BINARY_DIR})

# TODO: should be doing this using the targets approach?
if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

#find_package(GTest REQUIRED)
#find_package(Poco REQUIRED)

add_executable(hello main.cpp)

enable_testing()
add_executable(tester test.cpp)
target_link_libraries(tester PRIVATE CONAN_PKG::gtest)
add_test(BasicTester bin/tester)
