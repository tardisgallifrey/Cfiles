cmake_minimum_required(VERSION 3.20)

project(OpenGLHello)

#Set GL, GLU, and glut linker flags for GCC
SET(GCC_OPENGL_LINK_FLAGS    "-lGL -lGLU -lglut")

SET(CMAKE_EXE_LINKER_FLAGS  "${GCC_OPENGL_LINK_FLAGS}")

add_executable(OpenGLHello openglhello.c)