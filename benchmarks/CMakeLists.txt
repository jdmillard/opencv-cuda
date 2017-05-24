##################################
# Micro Benchmarking with Google #
##################################

set(GBENCH_DIR ${CMAKE_CURRENT_BINARY_DIR}/googlebenchmark-download)

set(CMAKE_MODULE_PATH ../cmake)

# Download and install googlebenchmark
configure_file(
	"${CMAKE_MODULE_PATH}/googlebenchmark.cmake.in"
	"${GBENCH_DIR}/CMakeLists.txt"
	IMMEDIATE @ONLY)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" . WORKING_DIRECTORY ${GBENCH_DIR} )
execute_process(COMMAND ${CMAKE_COMMAND} --build . WORKING_DIRECTORY ${GBENCH_DIR})

# Add googlebenchmark directly to the build. This defines the `gtest` and `gtest_main` targets. Don't add these
# targets to the ALL target so that `make install` will ignore googlebenchmark installation targets
add_subdirectory(${GBENCH_DIR}/googlebenchmark-src ${GBENCH_DIR}/googlebenchmark-build EXCLUDE_FROM_ALL)


find_package(OpenCV REQUIRED)

include_directories(${GBENCH_DIR}/googlebenchmark-src/include ../include ${OpenCV_INCLUDE_DIRS})



# Define tests here
add_executable(bench bench.cpp ../src/example.cpp)
target_link_libraries(bench benchmark ${OpenCV_LIBS})