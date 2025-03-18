cmake_minimum_required(VERSION 3.7)

if (DEFINED ENV{VCPKG_ROOT})
  set(VCPKG_CMAKE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
else ()
  set(VCPKG_CMAKE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")
endif ()

set(CMAKE_TOOLCHAIN_FILE ${VCPKG_CMAKE}) # n.b.

project(optflow-opencv)

find_package(OpenCV REQUIRED)

set(name fback)
add_executable(${name} ${name}.cpp)
target_include_directories(${name} PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${name} PRIVATE ${OpenCV_LIBRARIES})

set(name simple_fback)
add_executable(${name} ${name}.cpp)
target_include_directories(${name} PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${name} PRIVATE ${OpenCV_LIBRARIES})

set(name lkdemo)
add_executable(${name} ${name}.cpp)
target_include_directories(${name} PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${name} PRIVATE ${OpenCV_LIBRARIES})

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT fback)
