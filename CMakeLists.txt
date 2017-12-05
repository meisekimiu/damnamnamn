cmake_minimum_required(VERSION 2.8)
project(DAMNAMNAMN)

add_executable(damnamnamn src/main.cpp src/RecordingDevice.cpp)

target_link_libraries(damnamnamn fmodex64)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
