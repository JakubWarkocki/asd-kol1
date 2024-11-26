cmake_minimum_required(VERSION 3.10)
project(Asdy VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

target_include_directories(Asdy PUBLIC include)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

add_executable(PriorityQueueTesting ${SOURCE_FILES})

g