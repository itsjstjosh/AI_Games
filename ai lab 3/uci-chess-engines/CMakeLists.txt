cmake_minimum_required(VERSION 3.7)   # VS_STARTUP_PROPERTY
set(CMAKE_CXX_STANDARD 17)

project(uci-chess-engines)
add_executable(sunil-orig sunil-orig.cpp)
add_executable(sunil2-tidy sunil2-tidy.cpp)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT sunil2-tidy)
