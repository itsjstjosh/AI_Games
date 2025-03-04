cmake_minimum_required(VERSION 3.15)

set(DEPS "${CMAKE_CURRENT_SOURCE_DIR}/deps")

# Commented out - we are using a local vcpkg export provided with the lab
#if (DEFINED ENV{VCPKG_ROOT})
  set(VCPKG_CMAKE "${DEPS}/vcpkg-export/scripts/buildsystems/vcpkg.cmake")
  set(CMAKE_TOOLCHAIN_FILE ${VCPKG_CMAKE})
#endif ()

set(RLCPP "${DEPS}/raylib-cpp")
set(LIBOAI "${DEPS}/liboai/liboai/include")

project(chatbots-lab-exercises)

find_package(raylib CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(cpr CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED) # Also needed on Windows?

foreach(n 01-hello 02-images 03-completions 04-chatbot 05-raylib-chatbot)

  if ("05-raylib-chatbot" STREQUAL n)
    add_executable(${n} ${n}.cpp openai-helper.cpp openai-helper.hpp)
  else()
    add_executable(${n} ${n}.cpp)
  endif()

  target_compile_features(${n} PRIVATE cxx_std_17)

  target_include_directories(${n} PRIVATE ${raylib_INCLUDE_DIRS}) # needed?
  target_include_directories(${n} PRIVATE ${RLCPP}/include) # ${RLEXTRAS})
  target_include_directories(${n} PRIVATE ${LIBOAI})

#  target_link_directories(${n} PRIVATE ${LIBOAI}/lib)

  target_link_libraries(${n} PRIVATE oai)
  target_link_libraries(${n} PRIVATE raylib)
  target_link_libraries(${n} PRIVATE cpr::cpr)
  target_link_libraries(${n} PRIVATE nlohmann_json::nlohmann_json)

  if (UNIX)
    # No longer required:
    # target_link_libraries(${n} PRIVATE asan ubsan m dl pthread)
    target_link_libraries(${n} PRIVATE glfw)
  endif()

  # Or set as a CMake variable? (VS_DEBUGGER_ENVIRONMENT approach used here
  # is also used 1-lab-examples/CMakeLists.txt in constraint programming lab.)
  set_target_properties(${n} PROPERTIES VS_DEBUGGER_ENVIRONMENT "OPENAI_API_KEY=")

endforeach(n)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT 01-hello)
