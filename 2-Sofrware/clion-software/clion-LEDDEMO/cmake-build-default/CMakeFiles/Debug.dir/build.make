# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\CLion\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = D:\CLion\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\GitHub\STC51\2-Sofrware\clion-software\clion-LEDDEMO

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\GitHub\STC51\2-Sofrware\clion-software\clion-LEDDEMO\cmake-build-default

# Utility rule file for Debug.

# Include any custom commands dependencies for this target.
include CMakeFiles/Debug.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Debug.dir/progress.make

CMakeFiles/Debug:
	cd /d E:\GitHub\STC51\2-Sofrware\clion-software\clion-LEDDEMO && platformio -c clion debug -e

Debug: CMakeFiles/Debug
Debug: CMakeFiles/Debug.dir/build.make
.PHONY : Debug

# Rule to build all files generated by this target.
CMakeFiles/Debug.dir/build: Debug
.PHONY : CMakeFiles/Debug.dir/build

CMakeFiles/Debug.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Debug.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Debug.dir/clean

CMakeFiles/Debug.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\GitHub\STC51\2-Sofrware\clion-software\clion-LEDDEMO E:\GitHub\STC51\2-Sofrware\clion-software\clion-LEDDEMO E:\GitHub\STC51\2-Sofrware\clion-software\clion-LEDDEMO\cmake-build-default E:\GitHub\STC51\2-Sofrware\clion-software\clion-LEDDEMO\cmake-build-default E:\GitHub\STC51\2-Sofrware\clion-software\clion-LEDDEMO\cmake-build-default\CMakeFiles\Debug.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Debug.dir/depend

