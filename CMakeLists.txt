cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 20)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

project(efimov_d_a)
include(cmake/build_prefix.cmake)

add_subdirectory(prj.labs)
add_subdirectory(prj.test)