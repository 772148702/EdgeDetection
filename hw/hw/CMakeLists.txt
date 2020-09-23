# CMakeList.txt : CMake project for hw, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

find_package(libpng CONFIG REQUIRED)
# Add source to this project's executable.
add_executable (hw "hw.cpp" "hw.h")
target_link_libraries(hw PRIVATE png)
# TODO: Add tests and install targets if needed.
