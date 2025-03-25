cmake_minimum_required(VERSION 3.7)

if (DEFINED ENV{VCPKG_ROOT})
  set(VCPKG_CMAKE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
else ()
  set(VCPKG_CMAKE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")
endif ()
set(CMAKE_TOOLCHAIN_FILE ${VCPKG_CMAKE}) # n.b.

if (DEFINED ENV{AIPFG_DEPS})
  set(RLCPP "$ENV{AIPFG_DEPS}/raylib-cpp")
  set(RLEXTRAS "$ENV{AIPFG_DEPS}/raylib-extras")
  set(RESOURCES "$ENV{AIPFG_DEPS}/../resources")
else ()
  set(RLCPP "${CMAKE_CURRENT_SOURCE_DIR}/../deps/raylib-cpp")
  set(RLEXTRAS "${CMAKE_CURRENT_SOURCE_DIR}/../deps/raylib-extras")
  set(RESOURCES "${CMAKE_CURRENT_SOURCE_DIR}/../resources")
endif ()

add_compile_definitions(CMAKE_RLCPP="${RLCPP}")
add_compile_definitions(CMAKE_RESOURCES="${RESOURCES}")

project(lab8-sprites-concurrency)

find_package(raylib CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)  # Also needed on Windows?

foreach(n
01-scarfy
02-sprite-class
03-chrono-sleep
04-async-wait
05-async-wait-param
06-async-wait-param-ref
07-async-wait-param-ref-member
08-async-wait-param-ref-member-while
09-raylib-concurrency
)
  add_executable(${n} ${n}.cpp)
  #target_include_directories(${n} PRIVATE ${raylib_INCLUDE_DIRS})
  target_include_directories(${n} PRIVATE ${RLCPP}/include ${RLEXTRAS})
  target_link_libraries(${n} PRIVATE raylib)

  if (UNIX)
    string(TOUPPER "${CMAKE_BUILD_TYPE}" uppercase_CMAKE_BUILD_TYPE)

    # if (uppercase_CMAKE_BUILD_TYPE MATCHES RELEASE)
    #   target_link_libraries(${n} PRIVATE m dl pthread)
    # else ()
    #   target_link_libraries(${n} PRIVATE asan ubsan m dl pthread) # default
    # endif()

    if (UNIX)
      # No longer required:
      # target_link_libraries(${n} PRIVATE asan ubsan m dl pthread glfw)
      target_link_libraries(${n} PRIVATE glfw)
    endif()
  endif()

endforeach(n)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT 01-scarfy)

