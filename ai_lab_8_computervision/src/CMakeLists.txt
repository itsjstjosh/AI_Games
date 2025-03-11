cmake_minimum_required(VERSION 3.7)

# cmake_path might be useful in CMake 3.20. e.g.
# cmake_path(SET VCPKG_CMAKE "C:\vcpkg-export-20210207-193643\scripts\buildsystems\vcpkg.cmake")
# But it's not yet released....

if (DEFINED ENV{VCPKG_ROOT})
  set(VCPKG_CMAKE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
else ()
  set(VCPKG_CMAKE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")
endif ()
set(CMAKE_TOOLCHAIN_FILE ${VCPKG_CMAKE}) # n.b.

set(name ailab-opencv1)
project(${name}) # Setting CMAKE_TOOLCHAIN_FILE must precede "project"

find_package(OpenCV REQUIRED) # This must follow the "project" command

foreach(n
00_opencv_version
01_show_colour
02_show_image
03_capture_show_image
04_capture_show_video
05_capture_show_video_record
06_capture_show_video_grab_image
07_simple_facerec_eigenfaces
)
  add_executable(${n} ${n}.cpp)
  target_compile_features(${n} PRIVATE cxx_std_17) # for C++17 <filesystem>
  target_include_directories(${n} PRIVATE ${OpenCV_INCLUDE_DIRS})
  target_link_libraries(${n} ${OpenCV_LIBRARIES})
endforeach(n)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT 00_opencv_version)

