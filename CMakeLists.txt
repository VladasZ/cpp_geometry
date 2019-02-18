cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

include(${CMAKE_BINARY_DIR}/build_info.cmake)
include(${BUILD_SCRIPT_PATH})

set(CMAKE_CXX_STANDARD 17)

project(geometry)

add_catalog_recursive(${PROJECT_SOURCE_DIR} / SOURCE)
add_library(${PROJECT_NAME} ${SOURCE})

# if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
#   foreach(var ${GIT_DEPENDENCIES})
# 	add_subdirectory(${var} "${var}/dep_build")
#   endforeach()
# endif()

link_project_at_path(cpp_utils ${cpp_utils_path})
