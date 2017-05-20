cmake_minimum_required(VERSION 2.8)

# use c++ 11
set(CMAKE_CXX_STANDARD 11)

# set project name
project(opencv-testing)

# NOTE: a flaw is when a PC has CUDA but the user does not desire to use it
# or does not have OpenCV compiled from source

# a way to make find_package result silent?
find_package(CUDA)
if(CUDA_FOUND)
  message( "   " )
  message( STATUS "CUDA was found on this machine" )
  message( STATUS "version: " ${CUDA_VERSION} )
  message( STATUS ${CUDA_INCLUDE_DIRS} )
  message( "   " )

  # CUDA is installed. It is assumed that OpenCV was compiled from source in
  # order to use the cv::gpu:: namespace. The library installation directory
  # is assumed to be /usr/local/share/OpenCV/ unless otherwise specified by the
  # existence of the environment variable OpenCV_DIR. Check if an environment
  # variable has been manually set.

  if(DEFINED ENV{OpenCV_DIR})
    message(STATUS "OpenCV library path manually specified:")
    set(OpenCV_DIR $ENV{OpenCV_DIR})
  else()
    message(STATUS "Using expected OpenCV library installation:")
    set(OpenCV_DIR /usr/local/share/OpenCV/)
  endif()
  message(STATUS ${OpenCV_DIR})

else(CUDA_FOUND)
  message(STATUS "CUDA is not found on this machine" )
  message( "   " )
  message(STATUS "Using the OpenCV library from ROS:")
  message(STATUS ${OpenCV_DIR})
  
endif(CUDA_FOUND)

find_package(OpenCV REQUIRED)

message( "-- version: " ${OpenCV_VERSION} )
message( "-- " ${OpenCV_INCLUDE_DIRS} )
message( "-- " ${OpenCV_INSTALL_PATH} )
message( "-- " ${OpenCV_CONFIG_PATH} )
message( "   " )

# set include directory
include_directories(include)

# source files to compile
add_executable(opencv-testing
                src/main.cpp
                src/example.cpp)

# link OpenCV library
target_link_libraries(opencv-testing ${OpenCV_LIBS})