cmake_minimum_required(VERSION 3.0)
project(Interface)

set(LibrarySources
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
	secondmainwindow.ui
	secondmainwindow.cpp
	secondmainwindow.h
	
)

#CMake will handle the Qt moc preprocessor automatically, i.e. without having to use the QT4_WRAP_CPP()
set(CMAKE_AUTOMOC ON)

#CMake will handle the Qt uic code generator automatically, i.e. without having to use the QT4_WRAP_UI()
set(CMAKE_AUTOUIC ON)

add_definitions(-DUI_EXPORT)
add_library(${PROJECT_NAME} SHARED ${LibrarySources})

#Find OpenCV
if( NOT OpenCV_FOUND )
	find_package(OpenCV REQUIRED)
endif()

#Find Qt
if( NOT Qt5Widgets_FOUND )
	find_package(Qt5Widgets REQUIRED)
endif()

if( NOT Qt5Core_FOUND )
	find_package(Qt5Core REQUIRED)
endif()


target_link_libraries(${PROJECT_NAME} 
		      Algorithms.lib
		      Utils.lib
		      Qt5::Widgets 
		      Qt5::Core
		      ${OpenCV_LIBS}
	      	      )

target_include_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_SOURCE_DIR}/Sources/Algorithms
	${CMAKE_SOURCE_DIR}/Sources/Utils
	${OpenCV_INCLUDE_DIRS}
	
)

add_dependencies(${PROJECT_NAME}
			Algorithms
			Utils
			)

#Link this project with the runtime output dir. Algo and Utils are also linked to this 
target_link_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)


install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION "${CMAKE_BINARY_DIR}/DeliveryPackage/bin"
        LIBRARY DESTINATION "${CMAKE_BINARY_DIR}/DeliveryPackage/lib"
		)
