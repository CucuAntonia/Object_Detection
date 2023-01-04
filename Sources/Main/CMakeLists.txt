cmake_minimum_required(VERSION 3.0)
project(ObjDetectionMain)

set( AppSources
	main.cpp
)

add_executable(${PROJECT_NAME} ${AppSources})

#Find OpenCV
if( NOT OpenCV_FOUND )
	find_package(OpenCV REQUIRED)
endif()
	
#Find Qt package
if( NOT Qt5Gui_FOUND )
	find_package(Qt5Gui REQUIRED)
endif()

if( NOT Qt5Widgets_FOUND )
	find_package(Qt5Widgets REQUIRED)
endif()

add_dependencies(${PROJECT_NAME}
	Algorithms
	Interface
)

target_include_directories(${PROJECT_NAME} PUBLIC
	${OpenCV_INCLUDE_DIRS}
	${CMAKE_SOURCE_DIR}/Sources/Algorithms
	${CMAKE_SOURCE_DIR}/Sources/Interface

	
)

#Link this project with the runtime output dir.
target_link_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

target_link_libraries(${PROJECT_NAME} 
	Qt5::Gui
	Qt5::Widgets
	${OpenCV_LIBS}
	Algorithms.lib
	Interface.lib
)





