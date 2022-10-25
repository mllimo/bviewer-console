cmake_minimum_required (VERSION 3.8)

get_filename_component(PARENT_DIR ../ ABSOLUTE)

add_library(Bytes STATIC
	${CMAKE_CURRENT_SOURCE_DIR}/c/byte.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/c/bytes.cpp

)

target_include_directories(Bytes PUBLIC ${PARENT_DIR})

