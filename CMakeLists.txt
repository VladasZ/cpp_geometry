cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

include(${CMAKE_BINARY_DIR}/build_info.cmake)
include(${CMAKE_BINARY_DIR}/${BUILD_INFO})
include(${BUILD_SCRIPT_PATH})

set(CMAKE_CXX_STANDARD 17)

project(geometry)

add_catalog_recursive(${PROJECT_SOURCE_DIR} / SOURCE)
add_library(${PROJECT_NAME} ${SOURCE})

conan_basic_setup()
conan_target_link_libraries(${PROJECT_NAME})
