# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.23.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.23.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/grongo/Assignments/cps1012/bin

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/grongo/Assignments/cps1012/build

# Include any dependencies generated for this target.
include CMakeFiles/tish.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tish.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tish.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tish.dir/flags.make

CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/tinyshell.c.o: CMakeFiles/tish.dir/flags.make
CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/tinyshell.c.o: /Users/grongo/Assignments/cps1012/src/tinyshell.c
CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/tinyshell.c.o: CMakeFiles/tish.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/grongo/Assignments/cps1012/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/tinyshell.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/tinyshell.c.o -MF CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/tinyshell.c.o.d -o CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/tinyshell.c.o -c /Users/grongo/Assignments/cps1012/src/tinyshell.c

CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/tinyshell.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/tinyshell.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/grongo/Assignments/cps1012/src/tinyshell.c > CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/tinyshell.c.i

CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/tinyshell.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/tinyshell.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/grongo/Assignments/cps1012/src/tinyshell.c -o CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/tinyshell.c.s

CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/lib/linenoise.c.o: CMakeFiles/tish.dir/flags.make
CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/lib/linenoise.c.o: /Users/grongo/Assignments/cps1012/lib/linenoise.c
CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/lib/linenoise.c.o: CMakeFiles/tish.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/grongo/Assignments/cps1012/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/lib/linenoise.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/lib/linenoise.c.o -MF CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/lib/linenoise.c.o.d -o CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/lib/linenoise.c.o -c /Users/grongo/Assignments/cps1012/lib/linenoise.c

CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/lib/linenoise.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/lib/linenoise.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/grongo/Assignments/cps1012/lib/linenoise.c > CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/lib/linenoise.c.i

CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/lib/linenoise.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/lib/linenoise.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/grongo/Assignments/cps1012/lib/linenoise.c -o CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/lib/linenoise.c.s

CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/builtins.c.o: CMakeFiles/tish.dir/flags.make
CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/builtins.c.o: /Users/grongo/Assignments/cps1012/src/builtins.c
CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/builtins.c.o: CMakeFiles/tish.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/grongo/Assignments/cps1012/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/builtins.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/builtins.c.o -MF CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/builtins.c.o.d -o CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/builtins.c.o -c /Users/grongo/Assignments/cps1012/src/builtins.c

CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/builtins.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/builtins.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/grongo/Assignments/cps1012/src/builtins.c > CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/builtins.c.i

CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/builtins.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/builtins.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/grongo/Assignments/cps1012/src/builtins.c -o CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/builtins.c.s

# Object files for target tish
tish_OBJECTS = \
"CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/tinyshell.c.o" \
"CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/lib/linenoise.c.o" \
"CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/builtins.c.o"

# External object files for target tish
tish_EXTERNAL_OBJECTS =

tish: CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/tinyshell.c.o
tish: CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/lib/linenoise.c.o
tish: CMakeFiles/tish.dir/Users/grongo/Assignments/cps1012/src/builtins.c.o
tish: CMakeFiles/tish.dir/build.make
tish: CMakeFiles/tish.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/grongo/Assignments/cps1012/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable tish"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tish.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tish.dir/build: tish
.PHONY : CMakeFiles/tish.dir/build

CMakeFiles/tish.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tish.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tish.dir/clean

CMakeFiles/tish.dir/depend:
	cd /Users/grongo/Assignments/cps1012/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/grongo/Assignments/cps1012/bin /Users/grongo/Assignments/cps1012/bin /Users/grongo/Assignments/cps1012/build /Users/grongo/Assignments/cps1012/build /Users/grongo/Assignments/cps1012/build/CMakeFiles/tish.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tish.dir/depend
