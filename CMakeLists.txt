cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
	include(build/build_tools_generated.cmake)
	include(${CMAKE_UTILS_PATH})
	if(${NEEDS_CONAN})
	include(${CONAN_BUILD_INFO})
	endif()
endif()

set(CMAKE_CXX_STANDARD 17)

project(geometry)

add_catalog_recursive(${PROJECT_SOURCE_DIR} / SOURCE)
add_library(${PROJECT_NAME} ${SOURCE})
