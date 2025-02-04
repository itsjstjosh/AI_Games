cmake_minimum_required(VERSION 3.7)   # VS_STARTUP_PROPERTY
set(CMAKE_CXX_STANDARD 17)

project(nim)

add_executable(nim-sum nim-sum.cpp)
add_executable(nim nim.cpp)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT nim-sum)
