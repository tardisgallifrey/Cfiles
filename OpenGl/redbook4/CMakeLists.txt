cmake_minimum_required(VERSION 3.20)

#If you clear the build folder, you must 
#start and stop Code to reset Cmake
project(redbook4)

#These seem to not work
#Set GL, GLU, and glut linker flags for GCC
#SET(GCC_OPENGL_LINK_FLAGS    "-lGL -lGLU -lglut")
#SET(CMAKE_EXE_LINKER_FLAGS  "${GCC_OPENGL_LINK_FLAGS}")

add_executable(redbookex4 redbookex4.c)

#Use these instead
#m is math library
target_link_libraries(redbookex4 GL GLU GLEW GLX glut m)