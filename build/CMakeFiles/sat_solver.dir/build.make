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
CMAKE_SOURCE_DIR = "/Users/jakeanderson/Documents/Personal dev/sat_solver"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/jakeanderson/Documents/Personal dev/sat_solver/build"

# Include any dependencies generated for this target.
include CMakeFiles/sat_solver.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sat_solver.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sat_solver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sat_solver.dir/flags.make

CMakeFiles/sat_solver.dir/src/main.cpp.o: CMakeFiles/sat_solver.dir/flags.make
CMakeFiles/sat_solver.dir/src/main.cpp.o: /Users/jakeanderson/Documents/Personal\ dev/sat_solver/src/main.cpp
CMakeFiles/sat_solver.dir/src/main.cpp.o: CMakeFiles/sat_solver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/jakeanderson/Documents/Personal dev/sat_solver/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sat_solver.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sat_solver.dir/src/main.cpp.o -MF CMakeFiles/sat_solver.dir/src/main.cpp.o.d -o CMakeFiles/sat_solver.dir/src/main.cpp.o -c "/Users/jakeanderson/Documents/Personal dev/sat_solver/src/main.cpp"

CMakeFiles/sat_solver.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sat_solver.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/jakeanderson/Documents/Personal dev/sat_solver/src/main.cpp" > CMakeFiles/sat_solver.dir/src/main.cpp.i

CMakeFiles/sat_solver.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sat_solver.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/jakeanderson/Documents/Personal dev/sat_solver/src/main.cpp" -o CMakeFiles/sat_solver.dir/src/main.cpp.s

CMakeFiles/sat_solver.dir/src/sat_solver.cpp.o: CMakeFiles/sat_solver.dir/flags.make
CMakeFiles/sat_solver.dir/src/sat_solver.cpp.o: /Users/jakeanderson/Documents/Personal\ dev/sat_solver/src/sat_solver.cpp
CMakeFiles/sat_solver.dir/src/sat_solver.cpp.o: CMakeFiles/sat_solver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/jakeanderson/Documents/Personal dev/sat_solver/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sat_solver.dir/src/sat_solver.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sat_solver.dir/src/sat_solver.cpp.o -MF CMakeFiles/sat_solver.dir/src/sat_solver.cpp.o.d -o CMakeFiles/sat_solver.dir/src/sat_solver.cpp.o -c "/Users/jakeanderson/Documents/Personal dev/sat_solver/src/sat_solver.cpp"

CMakeFiles/sat_solver.dir/src/sat_solver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sat_solver.dir/src/sat_solver.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/jakeanderson/Documents/Personal dev/sat_solver/src/sat_solver.cpp" > CMakeFiles/sat_solver.dir/src/sat_solver.cpp.i

CMakeFiles/sat_solver.dir/src/sat_solver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sat_solver.dir/src/sat_solver.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/jakeanderson/Documents/Personal dev/sat_solver/src/sat_solver.cpp" -o CMakeFiles/sat_solver.dir/src/sat_solver.cpp.s

CMakeFiles/sat_solver.dir/src/utils.cpp.o: CMakeFiles/sat_solver.dir/flags.make
CMakeFiles/sat_solver.dir/src/utils.cpp.o: /Users/jakeanderson/Documents/Personal\ dev/sat_solver/src/utils.cpp
CMakeFiles/sat_solver.dir/src/utils.cpp.o: CMakeFiles/sat_solver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/jakeanderson/Documents/Personal dev/sat_solver/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sat_solver.dir/src/utils.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sat_solver.dir/src/utils.cpp.o -MF CMakeFiles/sat_solver.dir/src/utils.cpp.o.d -o CMakeFiles/sat_solver.dir/src/utils.cpp.o -c "/Users/jakeanderson/Documents/Personal dev/sat_solver/src/utils.cpp"

CMakeFiles/sat_solver.dir/src/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sat_solver.dir/src/utils.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/jakeanderson/Documents/Personal dev/sat_solver/src/utils.cpp" > CMakeFiles/sat_solver.dir/src/utils.cpp.i

CMakeFiles/sat_solver.dir/src/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sat_solver.dir/src/utils.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/jakeanderson/Documents/Personal dev/sat_solver/src/utils.cpp" -o CMakeFiles/sat_solver.dir/src/utils.cpp.s

# Object files for target sat_solver
sat_solver_OBJECTS = \
"CMakeFiles/sat_solver.dir/src/main.cpp.o" \
"CMakeFiles/sat_solver.dir/src/sat_solver.cpp.o" \
"CMakeFiles/sat_solver.dir/src/utils.cpp.o"

# External object files for target sat_solver
sat_solver_EXTERNAL_OBJECTS =

sat_solver: CMakeFiles/sat_solver.dir/src/main.cpp.o
sat_solver: CMakeFiles/sat_solver.dir/src/sat_solver.cpp.o
sat_solver: CMakeFiles/sat_solver.dir/src/utils.cpp.o
sat_solver: CMakeFiles/sat_solver.dir/build.make
sat_solver: CMakeFiles/sat_solver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/jakeanderson/Documents/Personal dev/sat_solver/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable sat_solver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sat_solver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sat_solver.dir/build: sat_solver
.PHONY : CMakeFiles/sat_solver.dir/build

CMakeFiles/sat_solver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sat_solver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sat_solver.dir/clean

CMakeFiles/sat_solver.dir/depend:
	cd "/Users/jakeanderson/Documents/Personal dev/sat_solver/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/jakeanderson/Documents/Personal dev/sat_solver" "/Users/jakeanderson/Documents/Personal dev/sat_solver" "/Users/jakeanderson/Documents/Personal dev/sat_solver/build" "/Users/jakeanderson/Documents/Personal dev/sat_solver/build" "/Users/jakeanderson/Documents/Personal dev/sat_solver/build/CMakeFiles/sat_solver.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/sat_solver.dir/depend
