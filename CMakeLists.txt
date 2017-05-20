cmake_minimum_required(VERSION 2.8)

# use c++ 11
set(CMAKE_CXX_STANDARD 11)

# set project name
project(opencv-cuda)

# The user has the ability to ignore CUDA and the CUDA-enabled OpenCV libraries
# by manually creating and setting the environment variable IGNORE_CUDA to 1.
# This may be helpful for benchmarking. Bash commands: export IGNORE_CUDA=1
if(DEFINED ENV{IGNORE_CUDA})
  set(IGNORE_CUDA $ENV{IGNORE_CUDA})
  message(STATUS "CUDA ignore status is manually set to " ${IGNORE_CUDA})
else()
  set(IGNORE_CUDA 0)
endif()


find_package(CUDA QUIET)
if(CUDA_FOUND AND NOT(IGNORE_CUDA))
  message(STATUS "CUDA was found on this machine")
  message(STATUS "version: " ${CUDA_VERSION})
  message(STATUS ${CUDA_INCLUDE_DIRS})
  message("   ")

  # Add a definition to be used by the preprocessor directives
  add_definitions(-DCUDA=1)

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

else()
  if(IGNORE_CUDA)
    message(STATUS "CUDA is being ignored by request")
  else()
    message(STATUS "CUDA was not found on this machine")
  endif()
  message( "   " )
  message(STATUS "Using the OpenCV library from ROS without GPU:")
  message(STATUS ${OpenCV_DIR})

endif()

find_package(OpenCV REQUIRED)
message(STATUS "version: " ${OpenCV_VERSION})
message(STATUS ${OpenCV_INCLUDE_DIRS})
message(STATUS ${OpenCV_INSTALL_PATH})
message(STATUS ${OpenCV_CONFIG_PATH})
message("   ")

# set include directory
include_directories(include
                    ${OpenCV_INCLUDE_DIRS})

# source files to compile
add_executable(opencv-cuda
               src/main.cpp
               src/example.cpp)

# link OpenCV library
target_link_libraries(opencv-cuda ${OpenCV_LIBS})