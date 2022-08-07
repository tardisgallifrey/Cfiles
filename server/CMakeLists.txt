cmake_minimum_required(VERSION 3.10)

# set the project name
project(webserver VERSION 1.0)

# add the executable
add_executable(webserver http.c webserver.c)

