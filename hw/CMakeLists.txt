# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_TOOLCHAIN_FILE "./third_part/export/scripts/buildsystems/vcpkg.cmake")
#set(RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
message(STATUS "Using toolchain file: ${CMAKE_TOOLCHAIN_FILE}.")


project ("hw")

find_package(libpng CONFIG REQUIRED)
include_directories(third_part/include)
# Include sub-projects.
add_subdirectory ("hw")
add_subdirectory ("gui")
