# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shinigami/Documents/P_wdUnix/Unix-ProgramowanieSystemowe

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shinigami/Documents/P_wdUnix/Unix-ProgramowanieSystemowe/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/F1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/F1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/F1.dir/flags.make

CMakeFiles/F1.dir/f1.c.o: CMakeFiles/F1.dir/flags.make
CMakeFiles/F1.dir/f1.c.o: ../f1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shinigami/Documents/P_wdUnix/Unix-ProgramowanieSystemowe/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/F1.dir/f1.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/F1.dir/f1.c.o   -c /home/shinigami/Documents/P_wdUnix/Unix-ProgramowanieSystemowe/f1.c

CMakeFiles/F1.dir/f1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/F1.dir/f1.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shinigami/Documents/P_wdUnix/Unix-ProgramowanieSystemowe/f1.c > CMakeFiles/F1.dir/f1.c.i

CMakeFiles/F1.dir/f1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/F1.dir/f1.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shinigami/Documents/P_wdUnix/Unix-ProgramowanieSystemowe/f1.c -o CMakeFiles/F1.dir/f1.c.s

CMakeFiles/F1.dir/f1.c.o.requires:

.PHONY : CMakeFiles/F1.dir/f1.c.o.requires

CMakeFiles/F1.dir/f1.c.o.provides: CMakeFiles/F1.dir/f1.c.o.requires
	$(MAKE) -f CMakeFiles/F1.dir/build.make CMakeFiles/F1.dir/f1.c.o.provides.build
.PHONY : CMakeFiles/F1.dir/f1.c.o.provides

CMakeFiles/F1.dir/f1.c.o.provides.build: CMakeFiles/F1.dir/f1.c.o


# Object files for target F1
F1_OBJECTS = \
"CMakeFiles/F1.dir/f1.c.o"

# External object files for target F1
F1_EXTERNAL_OBJECTS =

F1: CMakeFiles/F1.dir/f1.c.o
F1: CMakeFiles/F1.dir/build.make
F1: CMakeFiles/F1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shinigami/Documents/P_wdUnix/Unix-ProgramowanieSystemowe/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable F1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/F1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/F1.dir/build: F1

.PHONY : CMakeFiles/F1.dir/build

CMakeFiles/F1.dir/requires: CMakeFiles/F1.dir/f1.c.o.requires

.PHONY : CMakeFiles/F1.dir/requires

CMakeFiles/F1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/F1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/F1.dir/clean

CMakeFiles/F1.dir/depend:
	cd /home/shinigami/Documents/P_wdUnix/Unix-ProgramowanieSystemowe/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shinigami/Documents/P_wdUnix/Unix-ProgramowanieSystemowe /home/shinigami/Documents/P_wdUnix/Unix-ProgramowanieSystemowe /home/shinigami/Documents/P_wdUnix/Unix-ProgramowanieSystemowe/cmake-build-debug /home/shinigami/Documents/P_wdUnix/Unix-ProgramowanieSystemowe/cmake-build-debug /home/shinigami/Documents/P_wdUnix/Unix-ProgramowanieSystemowe/cmake-build-debug/CMakeFiles/F1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/F1.dir/depend

