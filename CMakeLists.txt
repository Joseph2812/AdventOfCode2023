# CMakeList.txt : CMake project for AdventOfCode2023, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("AdventOfCode2023")

# Add source to this project's executable.
add_executable (AdventOfCode2023 "src/AdventOfCode2023.cpp" "include/AdventOfCode2023.hpp" "src/solutions/day1/Day1.cpp"  "include/solutions/day1/Day1.hpp"  "src/solutions/day1/WordMap.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET AdventOfCode2023 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
