cmake_minimum_required(VERSION 3.10)

project(SATSolver VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(sat_solver ${SOURCES})

enable_testing()
add_subdirectory(tests)
