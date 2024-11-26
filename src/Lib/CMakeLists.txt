# CMakeList.txt : CMake project for ProcessorSimulator, include source and define
# project specific logic here.
#

# Add source to this project's executable.

file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library (${PROJECT_NAME}Lib INTERFACE ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME}Lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

#if (CMAKE_VERSION VERSION_GREATER 3.12)
#  set_property(TARGET ${PROJECT_NAME}Lib PROPERTY CXX_STANDARD 20)
#endif()

# TODO: Add tests and install targets if needed.
