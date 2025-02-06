cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME example)	 
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable("${PROJECT_NAME}" main.cpp)

target_include_directories("${PROJECT_NAME}" SYSTEM PUBLIC ${CMAKE_SOURCE_DIR})