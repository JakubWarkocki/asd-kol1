cmake_minimum_required(VERSION 3.10)

project(asd-kol1 VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

add_executable(asd-kol1 ${SOURCE_FILES})

target_include_directories(asd-kol1 PRIVATE include)
target_compile_options(asd-kol1 PRIVATE -O2 -Wall -Wextra -Wpedantic)
