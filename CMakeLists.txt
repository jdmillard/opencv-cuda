cmake_minimum_required(VERSION 2.8)

# use c++ 11
set(CMAKE_CXX_STANDARD 11)

# set project name
project(opencv-testing)

find_package(OpenCV REQUIRED)

# set include directory
include_directories(include)

# source files to compile
add_executable(opencv-testing
                src/main.cpp
                src/example.cpp)

# link OpenCV library
target_link_libraries(opencv-testing ${OpenCV_LIBS})