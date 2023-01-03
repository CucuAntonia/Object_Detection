cmake_minimum_required(VERSION 3.0)
project(Algorithms)

set(LibrarySources
	Algorithms.h
	Algorithms.cpp
)

add_definitions(-DALGORITHMS_EXPORT)
add_library(${PROJECT_NAME} SHARED ${LibrarySources})

#Find OpenCV
if( NOT OpenCV_FOUND )
	find_package(OpenCV REQUIRED)
endif()

target_include_directories(${PROJECT_NAME} PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION "${CMAKE_BINARY_DIR}/DeliveryPackage/bin"
        LIBRARY DESTINATION "${CMAKE_BINARY_DIR}/DeliveryPackage/lib"
		)




