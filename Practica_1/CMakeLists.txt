cmake_minimum_required(VERSION 2.8)
if(COMMAND cmake_policy)
      cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

PROJECT(practica1)
find_package(GLUT)
find_package(OpenGL)
find_package(JPEG)

include_directories(library ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${JPEG_INCLUDE_DIR})
include_directories( include )
set(LIB_SOURCES 		
		
		user_code.cc
		user_code.h
		practica1.cc
		vertex.h
)
add_executable(practica1  ${LIB_SOURCES})


target_link_libraries( practica1 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${JPEG_LIBRARY} )