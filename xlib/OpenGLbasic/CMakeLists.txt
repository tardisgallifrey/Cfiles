# use cmake minimum version
cmake_minimum_required(VERSION 3.20)

# set the project name (and output executable)
set(PROJECT "basic_window")

# set project version number
# version number is a string "major.minor.patch"
project(${PROJECT} VERSION "0.1.1")

# create version.h header from template stored in version.h.in
configure_file(${CMAKE_SOURCE_DIR}/version.h.in ${CMAKE_SOURCE_DIR}/version.h)

# add the executable
add_executable(${PROJECT} fifthx.c)

# set the X11 and OpenGL libraries to link against
target_link_libraries(${PROJECT_NAME} X11 GL GLU)

# set target include directories
target_include_directories(${PROJECT} PUBLIC "${PROJECT_BINARY_DIR}")

