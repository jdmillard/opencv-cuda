cmake_minimum_required(VERSION 2.8)

# use c++ 11
set(CMAKE_CXX_STANDARD 11)

# set project name
project(opencv-testing)

# find_package (BZip2)
# if (BZIP2_FOUND)
#   include_directories(${BZIP_INCLUDE_DIRS})
#   target_link_libraries (helloworld ${BZIP2_LIBRARIES})
# else (BZip2)
#   stuffs
# endif (BZIP2_FOUND)

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