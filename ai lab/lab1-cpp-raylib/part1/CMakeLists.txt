cmake_minimum_required(VERSION 3.7)

project(lab1-cpp)

set(n name-age)
add_executable(${n} ${n}.cpp)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT ${n})

