cmake_minimum_required (VERSION 3.8)

get_filename_component(PARENT_DIR ../ ABSOLUTE)

add_executable (bviewer 
	${CMAKE_CURRENT_SOURCE_DIR}/c/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/c/console_view.cpp
)

target_link_directories(bviewer PRIVATE ${PARENT_DIR})

target_link_libraries(bviewer Bytes)

