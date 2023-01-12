cmake_minimum_required(VERSION 3.0)
project(Utils)

set(LibrarySources
	Utils.h
	Utils.cpp
	Camera.cpp
	Camera.h
)

add_definitions(-DUTILS_EXPORT)
add_library(${PROJECT_NAME} SHARED ${LibrarySources})

#Find OpenCV
if( NOT OpenCV_FOUND )
	find_package(OpenCV REQUIRED)
endif()

target_include_directories(${PROJECT_NAME} PUBLIC ${OpenCV_INCLUDE_DIRS})

#Find QT package
if( NOT Qt5Widgets_FOUND )
	find_package(Qt5Widgets REQUIRED)
endif()

target_link_libraries(${PROJECT_NAME} 
			Qt5::Widgets
			${OpenCV_LIBS})

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION "${CMAKE_BINARY_DIR}/DeliveryPackage/bin"
        LIBRARY DESTINATION "${CMAKE_BINARY_DIR}/DeliveryPackage/lib"
		)


