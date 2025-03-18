cmake_minimum_required(VERSION 3.5.0)

# Ubuntu does not include xfeatures2d.hpp required by matchingSURF.cpp
# Vcpkg does include xfeatures2d.hpp, but not the SIFT capability. This is
# mentioned in the lab notes.

if (DEFINED ENV{VCPKG_ROOT})
  set(VCPKG_CMAKE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
else ()
  set(VCPKG_CMAKE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")
endif ()

set(CMAKE_TOOLCHAIN_FILE ${VCPKG_CMAKE}) # n.b.

project(opencv_essentials)

set(ch5 packtpub/4244OS_05_Code)
FILE(GLOB cpp_files ${ch5}/*/*.cpp)

find_package(OpenCV REQUIRED) # This must follow the "project" command

foreach(p ${cpp_files})
  get_filename_component(n "${p}" NAME_WE) # NAME_WE - name without extension
  add_executable(${n} ${p})
  target_include_directories(${n} PRIVATE ${OpenCV_INCLUDE_DIRS})
  target_link_libraries(${n} PRIVATE ${OpenCV_LIBRARIES})
endforeach(p)
