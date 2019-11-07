cmake_minimum_required(VERSION 3.5)
project( opencv_demo)

set(CMAKE_BUILD_TYPE "Release")
set( CMAKE_CXX_FLAGS "-std=c++11 " )
set( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set( LIBRARY_OUTPUT_PATH ${ PROJECT_SOURCE_DIR}/lib)

#opencv 

find_package ( OpenCV REQUIRED)
if( NOT OpenCV_FOUND)
	message( FATAL_ERROR "OpenCV not found in ${OpenCV_DIR}")
endif(NOT OpenCV_FOUND)
include_directories( ${OpenCV_INCLUDE_DIRS})

set(THIRD_PARTY_LIBS
	${OpenCV_LIBS}
)

include_directories(${PROJECT_SOURCE_DIR}/include )
add_subdirectory(src)