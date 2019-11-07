add_executable(stackl_test stackl_test.cpp)
target_link_libraries(stackl_test stackl)
set_property(TARGET stackl_test PROPERTY CXX_STANDARD 17)