# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tardis1/Cfiles/OpenGl/hello

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tardis1/Cfiles/OpenGl/hello/build

# Include any dependencies generated for this target.
include CMakeFiles/OpenGLHello.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/OpenGLHello.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/OpenGLHello.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OpenGLHello.dir/flags.make

CMakeFiles/OpenGLHello.dir/openglhello.c.o: CMakeFiles/OpenGLHello.dir/flags.make
CMakeFiles/OpenGLHello.dir/openglhello.c.o: ../openglhello.c
CMakeFiles/OpenGLHello.dir/openglhello.c.o: CMakeFiles/OpenGLHello.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tardis1/Cfiles/OpenGl/hello/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/OpenGLHello.dir/openglhello.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/OpenGLHello.dir/openglhello.c.o -MF CMakeFiles/OpenGLHello.dir/openglhello.c.o.d -o CMakeFiles/OpenGLHello.dir/openglhello.c.o -c /home/tardis1/Cfiles/OpenGl/hello/openglhello.c

CMakeFiles/OpenGLHello.dir/openglhello.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/OpenGLHello.dir/openglhello.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tardis1/Cfiles/OpenGl/hello/openglhello.c > CMakeFiles/OpenGLHello.dir/openglhello.c.i

CMakeFiles/OpenGLHello.dir/openglhello.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/OpenGLHello.dir/openglhello.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tardis1/Cfiles/OpenGl/hello/openglhello.c -o CMakeFiles/OpenGLHello.dir/openglhello.c.s

# Object files for target OpenGLHello
OpenGLHello_OBJECTS = \
"CMakeFiles/OpenGLHello.dir/openglhello.c.o"

# External object files for target OpenGLHello
OpenGLHello_EXTERNAL_OBJECTS =

OpenGLHello: CMakeFiles/OpenGLHello.dir/openglhello.c.o
OpenGLHello: CMakeFiles/OpenGLHello.dir/build.make
OpenGLHello: CMakeFiles/OpenGLHello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tardis1/Cfiles/OpenGl/hello/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable OpenGLHello"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OpenGLHello.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OpenGLHello.dir/build: OpenGLHello
.PHONY : CMakeFiles/OpenGLHello.dir/build

CMakeFiles/OpenGLHello.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OpenGLHello.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OpenGLHello.dir/clean

CMakeFiles/OpenGLHello.dir/depend:
	cd /home/tardis1/Cfiles/OpenGl/hello/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tardis1/Cfiles/OpenGl/hello /home/tardis1/Cfiles/OpenGl/hello /home/tardis1/Cfiles/OpenGl/hello/build /home/tardis1/Cfiles/OpenGl/hello/build /home/tardis1/Cfiles/OpenGl/hello/build/CMakeFiles/OpenGLHello.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OpenGLHello.dir/depend

