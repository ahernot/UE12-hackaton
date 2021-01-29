cmake_minimum_required(VERSION 3.0.0)
project(rogue VERSION 0.1.0)

include_directories(include)

file(GLOB src "src/*.cpp")
file(GLOB include "include/*.h")

add_executable(rogue main.cpp ${src})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
