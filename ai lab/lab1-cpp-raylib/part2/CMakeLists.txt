cmake_minimum_required(VERSION 3.7)

if (DEFINED ENV{VCPKG_ROOT})
  set(VCPKG_CMAKE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
else ()
  set(VCPKG_CMAKE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")
endif ()

set(CMAKE_TOOLCHAIN_FILE ${VCPKG_CMAKE}) # n.b.

set(RLCPP "${CMAKE_CURRENT_SOURCE_DIR}/../../raylib-cpp-5.5.0")
set(RLEXTRAS "${CMAKE_CURRENT_SOURCE_DIR}/../../raylib-extras")

project(lab1-raylib)

find_package(raylib CONFIG REQUIRED)

foreach(n raylib1 raylib1-fullscreen raylib2) # raylib3)
  add_executable(${n} ${n}.cpp)
  target_include_directories(${n} PRIVATE ${raylib_INCLUDE_DIRS})
  target_include_directories(${n} PRIVATE ${RLCPP}/include ${RLEXTRAS})
  target_link_libraries(${n} PRIVATE raylib)
  target_compile_features(${n} PRIVATE cxx_std_17)

  if (UNIX)
    # asan and ubsan now seem required, even with a non-Debug build.
    target_link_libraries(${n} PRIVATE asan ubsan m dl pthread)
  endif()

endforeach(n)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT raylib1)

