cmake_minimum_required(VERSION 3.15)
project(MAPF VERSION 0.1
	     DESCRIPTION "Multi-Agent Pathfinding")

add_library(mapf_lib source/lib/Obstacles.cpp)
target_include_directories(mapf_lib PUBLIC include)

include(CTest)
enable_testing()

set(GTEST_ROOT /usr/src/gtest)
find_package(GTest REQUIRED)
add_executable(test_trivial test/test_trivial.cpp)
add_executable(test_dimension test/test_dimension.cpp)
add_executable(test_position test/test_position.cpp)

target_link_libraries(test_trivial PRIVATE GTest::gtest_main mapf_lib pthread)
target_link_libraries(test_dimension PRIVATE GTest::gtest_main mapf_lib pthread)
target_link_libraries(test_position PRIVATE GTest::gtest_main mapf_lib pthread)



include(GoogleTest)
gtest_discover_tests(test_trivial)
gtest_discover_tests(test_dimension)
gtest_discover_tests(test_position)
