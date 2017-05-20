cmake_minimum_required(VERSION 2.8)

# use c++ 11
set(CMAKE_CXX_STANDARD 11)

# set project name
project(opencv-testing)

find_package(CUDA)
if(CUDA_FOUND)
  message( "CUDA found" )
  #include_directories(${BZIP_INCLUDE_DIRS})
  #target_link_libraries (helloworld ${BZIP2_LIBRARIES})
else(CUDA_FOUND)
  message( "CUDA not found" )
endif(CUDA_FOUND)

find_package(OpenCV REQUIRED)

message( "   " )
message( "-- " ${OpenCV_VERSION} )
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