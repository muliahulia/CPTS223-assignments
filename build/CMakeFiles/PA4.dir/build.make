# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/juliasmith/Documents/CPTS223-Assignments/PA4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/juliasmith/Documents/CPTS223-Assignments/PA4/build

# Include any dependencies generated for this target.
include CMakeFiles/PA4.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/PA4.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/PA4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PA4.dir/flags.make

CMakeFiles/PA4.dir/main.cpp.o: CMakeFiles/PA4.dir/flags.make
CMakeFiles/PA4.dir/main.cpp.o: /Users/juliasmith/Documents/CPTS223-Assignments/PA4/main.cpp
CMakeFiles/PA4.dir/main.cpp.o: CMakeFiles/PA4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/juliasmith/Documents/CPTS223-Assignments/PA4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PA4.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PA4.dir/main.cpp.o -MF CMakeFiles/PA4.dir/main.cpp.o.d -o CMakeFiles/PA4.dir/main.cpp.o -c /Users/juliasmith/Documents/CPTS223-Assignments/PA4/main.cpp

CMakeFiles/PA4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/PA4.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/juliasmith/Documents/CPTS223-Assignments/PA4/main.cpp > CMakeFiles/PA4.dir/main.cpp.i

CMakeFiles/PA4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/PA4.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/juliasmith/Documents/CPTS223-Assignments/PA4/main.cpp -o CMakeFiles/PA4.dir/main.cpp.s

# Object files for target PA4
PA4_OBJECTS = \
"CMakeFiles/PA4.dir/main.cpp.o"

# External object files for target PA4
PA4_EXTERNAL_OBJECTS =

PA4: CMakeFiles/PA4.dir/main.cpp.o
PA4: CMakeFiles/PA4.dir/build.make
PA4: CMakeFiles/PA4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/juliasmith/Documents/CPTS223-Assignments/PA4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PA4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PA4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PA4.dir/build: PA4
.PHONY : CMakeFiles/PA4.dir/build

CMakeFiles/PA4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PA4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PA4.dir/clean

CMakeFiles/PA4.dir/depend:
	cd /Users/juliasmith/Documents/CPTS223-Assignments/PA4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/juliasmith/Documents/CPTS223-Assignments/PA4 /Users/juliasmith/Documents/CPTS223-Assignments/PA4 /Users/juliasmith/Documents/CPTS223-Assignments/PA4/build /Users/juliasmith/Documents/CPTS223-Assignments/PA4/build /Users/juliasmith/Documents/CPTS223-Assignments/PA4/build/CMakeFiles/PA4.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/PA4.dir/depend

