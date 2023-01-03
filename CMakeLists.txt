cmake_minimum_required(VERSION 3.0)

project(ObjectDetection)

if(CMAKE_CL_64)
		set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
		set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
		set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
							 
endif()


find_package(OpenCV REQUIRED)
find_package(Qt5Widgets REQUIRED)

add_subdirectory(Sources)