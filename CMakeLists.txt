cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR} "${CMAKE_SOURCE_DIR}/cmake/")

project(scotty-ui)

add_subdirectory(src)

add_executable(demo demo.c)

target_link_libraries(demo PUBLIC
	scotty-ui
)
