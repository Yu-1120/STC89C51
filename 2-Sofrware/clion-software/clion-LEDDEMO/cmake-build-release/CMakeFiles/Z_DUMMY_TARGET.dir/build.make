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
CMAKE_BINARY_DIR = E:\GitHub\STC51\2-Sofrware\clion-software\clion-LEDDEMO\cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/Z_DUMMY_TARGET.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Z_DUMMY_TARGET.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Z_DUMMY_TARGET.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Z_DUMMY_TARGET.dir/flags.make

CMakeFiles/Z_DUMMY_TARGET.dir/src/delay.cpp.obj: CMakeFiles/Z_DUMMY_TARGET.dir/flags.make
CMakeFiles/Z_DUMMY_TARGET.dir/src/delay.cpp.obj: ../src/delay.cpp
CMakeFiles/Z_DUMMY_TARGET.dir/src/delay.cpp.obj: CMakeFiles/Z_DUMMY_TARGET.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\GitHub\STC51\2-Sofrware\clion-software\clion-LEDDEMO\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Z_DUMMY_TARGET.dir/src/delay.cpp.obj"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Z_DUMMY_TARGET.dir/src/delay.cpp.obj -MF CMakeFiles\Z_DUMMY_TARGET.dir\src\delay.cpp.obj.d -o CMakeFiles\Z_DUMMY_TARGET.dir\src\delay.cpp.obj -c E:\GitHub\STC51\2-Sofrware\clion-software\clion-LEDDEMO\src\delay.cpp

CMakeFiles/Z_DUMMY_TARGET.dir/src/delay.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Z_DUMMY_TARGET.dir/src/delay.cpp.i"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\GitHub\STC51\2-Sofrware\clion-software\clion-LEDDEMO\src\delay.cpp > CMakeFiles\Z_DUMMY_TARGET.dir\src\delay.cpp.i

CMakeFiles/Z_DUMMY_TARGET.dir/src/delay.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Z_DUMMY_TARGET.dir/src/delay.cpp.s"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\GitHub\STC51\2-Sofrware\clion-software\clion-LEDDEMO\src\delay.cpp -o CMakeFiles\Z_DUMMY_TARGET.dir\src\delay.cpp.s

CMakeFiles/Z_DUMMY_TARGET.dir/src/main.c.obj: CMakeFiles/Z_DUMMY_TARGET.dir/flags.make
CMakeFiles/Z_DUMMY_TARGET.dir/src/main.c.obj: ../src/main.c
CMakeFiles/Z_DUMMY_TARGET.dir/src/main.c.obj: CMakeFiles/Z_DUMMY_TARGET.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\GitHub\STC51\2-Sofrware\clion-software\clion-LEDDEMO\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Z_DUMMY_TARGET.dir/src/main.c.obj"
	C:\Users\11868\.platformio\packages\toolchain-sdcc\bin\sdcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Z_DUMMY_TARGET.dir/src/main.c.obj -MF CMakeFiles\Z_DUMMY_TARGET.dir\src\main.c.obj.d -o CMakeFiles\Z_DUMMY_TARGET.dir\src\main.c.obj -c E:\GitHub\STC51\2-Sofrware\clion-software\clion-LEDDEMO\src\main.c

CMakeFiles/Z_DUMMY_TARGET.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Z_DUMMY_TARGET.dir/src/main.c.i"
	C:\Users\11868\.platformio\packages\toolchain-sdcc\bin\sdcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\GitHub\STC51\2-Sofrware\clion-software\clion-LEDDEMO\src\main.c > CMakeFiles\Z_DUMMY_TARGET.dir\src\main.c.i

CMakeFiles/Z_DUMMY_TARGET.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Z_DUMMY_TARGET.dir/src/main.c.s"
	C:\Users\11868\.platformio\packages\toolchain-sdcc\bin\sdcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\GitHub\STC51\2-Sofrware\clion-software\clion-LEDDEMO\src\main.c -o CMakeFiles\Z_DUMMY_TARGET.dir\src\main.c.s

# Object files for target Z_DUMMY_TARGET
Z_DUMMY_TARGET_OBJECTS = \
"CMakeFiles/Z_DUMMY_TARGET.dir/src/delay.cpp.obj" \
"CMakeFiles/Z_DUMMY_TARGET.dir/src/main.c.obj"

# External object files for target Z_DUMMY_TARGET
Z_DUMMY_TARGET_EXTERNAL_OBJECTS =

Z_DUMMY_TARGET: CMakeFiles/Z_DUMMY_TARGET.dir/src/delay.cpp.obj
Z_DUMMY_TARGET: CMakeFiles/Z_DUMMY_TARGET.dir/src/main.c.obj
Z_DUMMY_TARGET: CMakeFiles/Z_DUMMY_TARGET.dir/build.make
Z_DUMMY_TARGET: CMakeFiles/Z_DUMMY_TARGET.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\GitHub\STC51\2-Sofrware\clion-software\clion-LEDDEMO\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Z_DUMMY_TARGET"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Z_DUMMY_TARGET.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Z_DUMMY_TARGET.dir/build: Z_DUMMY_TARGET
.PHONY : CMakeFiles/Z_DUMMY_TARGET.dir/build

CMakeFiles/Z_DUMMY_TARGET.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Z_DUMMY_TARGET.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Z_DUMMY_TARGET.dir/clean

CMakeFiles/Z_DUMMY_TARGET.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\GitHub\STC51\2-Sofrware\clion-software\clion-LEDDEMO E:\GitHub\STC51\2-Sofrware\clion-software\clion-LEDDEMO E:\GitHub\STC51\2-Sofrware\clion-software\clion-LEDDEMO\cmake-build-release E:\GitHub\STC51\2-Sofrware\clion-software\clion-LEDDEMO\cmake-build-release E:\GitHub\STC51\2-Sofrware\clion-software\clion-LEDDEMO\cmake-build-release\CMakeFiles\Z_DUMMY_TARGET.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Z_DUMMY_TARGET.dir/depend

