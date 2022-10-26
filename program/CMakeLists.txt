# CMakeList.txt: proyecto de CMake para byte-viewer, incluya el origen y defina
# la lógica específica del proyecto aquí.
#
cmake_minimum_required (VERSION 3.8)

get_filename_component(PARENT_DIR ../ ABSOLUTE)

# Agregue un origen al ejecutable de este proyecto.
add_executable (byte-viewer 
	${CMAKE_CURRENT_SOURCE_DIR}/c/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/c/console_view.cpp
)

target_link_directories(byte-viewer PRIVATE ${PARENT_DIR})

target_link_libraries(byte-viewer Bytes)

