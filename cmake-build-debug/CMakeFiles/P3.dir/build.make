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
include CMakeFiles/P3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/P3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/P3.dir/flags.make

CMakeFiles/P3.dir/p3.c.o: CMakeFiles/P3.dir/flags.make
CMakeFiles/P3.dir/p3.c.o: ../p3.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shinigami/Documents/P_wdUnix/Unix-ProgramowanieSystemowe/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/P3.dir/p3.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/P3.dir/p3.c.o   -c /home/shinigami/Documents/P_wdUnix/Unix-ProgramowanieSystemowe/p3.c

CMakeFiles/P3.dir/p3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/P3.dir/p3.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shinigami/Documents/P_wdUnix/Unix-ProgramowanieSystemowe/p3.c > CMakeFiles/P3.dir/p3.c.i

CMakeFiles/P3.dir/p3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/P3.dir/p3.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shinigami/Documents/P_wdUnix/Unix-ProgramowanieSystemowe/p3.c -o CMakeFiles/P3.dir/p3.c.s

CMakeFiles/P3.dir/p3.c.o.requires:

.PHONY : CMakeFiles/P3.dir/p3.c.o.requires

CMakeFiles/P3.dir/p3.c.o.provides: CMakeFiles/P3.dir/p3.c.o.requires
	$(MAKE) -f CMakeFiles/P3.dir/build.make CMakeFiles/P3.dir/p3.c.o.provides.build
.PHONY : CMakeFiles/P3.dir/p3.c.o.provides

CMakeFiles/P3.dir/p3.c.o.provides.build: CMakeFiles/P3.dir/p3.c.o


# Object files for target P3
P3_OBJECTS = \
"CMakeFiles/P3.dir/p3.c.o"

# External object files for target P3
P3_EXTERNAL_OBJECTS =

P3: CMakeFiles/P3.dir/p3.c.o
P3: CMakeFiles/P3.dir/build.make
P3: CMakeFiles/P3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shinigami/Documents/P_wdUnix/Unix-ProgramowanieSystemowe/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable P3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/P3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/P3.dir/build: P3

.PHONY : CMakeFiles/P3.dir/build

CMakeFiles/P3.dir/requires: CMakeFiles/P3.dir/p3.c.o.requires

.PHONY : CMakeFiles/P3.dir/requires

CMakeFiles/P3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/P3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/P3.dir/clean

CMakeFiles/P3.dir/depend:
	cd /home/shinigami/Documents/P_wdUnix/Unix-ProgramowanieSystemowe/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shinigami/Documents/P_wdUnix/Unix-ProgramowanieSystemowe /home/shinigami/Documents/P_wdUnix/Unix-ProgramowanieSystemowe /home/shinigami/Documents/P_wdUnix/Unix-ProgramowanieSystemowe/cmake-build-debug /home/shinigami/Documents/P_wdUnix/Unix-ProgramowanieSystemowe/cmake-build-debug /home/shinigami/Documents/P_wdUnix/Unix-ProgramowanieSystemowe/cmake-build-debug/CMakeFiles/P3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/P3.dir/depend

