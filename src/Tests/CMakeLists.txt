# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)


file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_executable (${PROJECT_NAME}Tests ${SOURCES} ${HEADERS})

find_package(boost_unit_test_framework CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME}Tests PRIVATE Boost::unit_test_framework)
target_link_libraries(${PROJECT_NAME}Lib)
