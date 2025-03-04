cmake_minimum_required(VERSION 3.15)

if (DEFINED ENV{VCPKG_ROOT})
  set(VCPKG_CMAKE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
else ()
  set(VCPKG_CMAKE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")
endif ()

set(CMAKE_TOOLCHAIN_FILE ${VCPKG_CMAKE}) # n.b.

set(name chatbots-lab)
project(${name})

add_subdirectory(src/deps/liboai/liboai)
add_subdirectory(src)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT 01-hello)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMakePredefinedTargets")

