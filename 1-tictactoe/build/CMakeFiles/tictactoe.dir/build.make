# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/nfs/home/kshrestha/Desktop/CS 482/cs482-fall2018/1-tictactoe"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/nfs/home/kshrestha/Desktop/CS 482/cs482-fall2018/1-tictactoe/build"

# Include any dependencies generated for this target.
include CMakeFiles/tictactoe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tictactoe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tictactoe.dir/flags.make

CMakeFiles/tictactoe.dir/src/tictac.cc.o: CMakeFiles/tictactoe.dir/flags.make
CMakeFiles/tictactoe.dir/src/tictac.cc.o: ../src/tictac.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/nfs/home/kshrestha/Desktop/CS 482/cs482-fall2018/1-tictactoe/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tictactoe.dir/src/tictac.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tictactoe.dir/src/tictac.cc.o -c "/nfs/home/kshrestha/Desktop/CS 482/cs482-fall2018/1-tictactoe/src/tictac.cc"

CMakeFiles/tictactoe.dir/src/tictac.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tictactoe.dir/src/tictac.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/nfs/home/kshrestha/Desktop/CS 482/cs482-fall2018/1-tictactoe/src/tictac.cc" > CMakeFiles/tictactoe.dir/src/tictac.cc.i

CMakeFiles/tictactoe.dir/src/tictac.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tictactoe.dir/src/tictac.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/nfs/home/kshrestha/Desktop/CS 482/cs482-fall2018/1-tictactoe/src/tictac.cc" -o CMakeFiles/tictactoe.dir/src/tictac.cc.s

CMakeFiles/tictactoe.dir/src/tictac.cc.o.requires:

.PHONY : CMakeFiles/tictactoe.dir/src/tictac.cc.o.requires

CMakeFiles/tictactoe.dir/src/tictac.cc.o.provides: CMakeFiles/tictactoe.dir/src/tictac.cc.o.requires
	$(MAKE) -f CMakeFiles/tictactoe.dir/build.make CMakeFiles/tictactoe.dir/src/tictac.cc.o.provides.build
.PHONY : CMakeFiles/tictactoe.dir/src/tictac.cc.o.provides

CMakeFiles/tictactoe.dir/src/tictac.cc.o.provides.build: CMakeFiles/tictactoe.dir/src/tictac.cc.o


CMakeFiles/tictactoe.dir/src/tictac_support.cc.o: CMakeFiles/tictactoe.dir/flags.make
CMakeFiles/tictactoe.dir/src/tictac_support.cc.o: ../src/tictac_support.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/nfs/home/kshrestha/Desktop/CS 482/cs482-fall2018/1-tictactoe/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tictactoe.dir/src/tictac_support.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tictactoe.dir/src/tictac_support.cc.o -c "/nfs/home/kshrestha/Desktop/CS 482/cs482-fall2018/1-tictactoe/src/tictac_support.cc"

CMakeFiles/tictactoe.dir/src/tictac_support.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tictactoe.dir/src/tictac_support.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/nfs/home/kshrestha/Desktop/CS 482/cs482-fall2018/1-tictactoe/src/tictac_support.cc" > CMakeFiles/tictactoe.dir/src/tictac_support.cc.i

CMakeFiles/tictactoe.dir/src/tictac_support.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tictactoe.dir/src/tictac_support.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/nfs/home/kshrestha/Desktop/CS 482/cs482-fall2018/1-tictactoe/src/tictac_support.cc" -o CMakeFiles/tictactoe.dir/src/tictac_support.cc.s

CMakeFiles/tictactoe.dir/src/tictac_support.cc.o.requires:

.PHONY : CMakeFiles/tictactoe.dir/src/tictac_support.cc.o.requires

CMakeFiles/tictactoe.dir/src/tictac_support.cc.o.provides: CMakeFiles/tictactoe.dir/src/tictac_support.cc.o.requires
	$(MAKE) -f CMakeFiles/tictactoe.dir/build.make CMakeFiles/tictactoe.dir/src/tictac_support.cc.o.provides.build
.PHONY : CMakeFiles/tictactoe.dir/src/tictac_support.cc.o.provides

CMakeFiles/tictactoe.dir/src/tictac_support.cc.o.provides.build: CMakeFiles/tictactoe.dir/src/tictac_support.cc.o


CMakeFiles/tictactoe.dir/src/tictac_turnin.cc.o: CMakeFiles/tictactoe.dir/flags.make
CMakeFiles/tictactoe.dir/src/tictac_turnin.cc.o: ../src/tictac_turnin.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/nfs/home/kshrestha/Desktop/CS 482/cs482-fall2018/1-tictactoe/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tictactoe.dir/src/tictac_turnin.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tictactoe.dir/src/tictac_turnin.cc.o -c "/nfs/home/kshrestha/Desktop/CS 482/cs482-fall2018/1-tictactoe/src/tictac_turnin.cc"

CMakeFiles/tictactoe.dir/src/tictac_turnin.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tictactoe.dir/src/tictac_turnin.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/nfs/home/kshrestha/Desktop/CS 482/cs482-fall2018/1-tictactoe/src/tictac_turnin.cc" > CMakeFiles/tictactoe.dir/src/tictac_turnin.cc.i

CMakeFiles/tictactoe.dir/src/tictac_turnin.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tictactoe.dir/src/tictac_turnin.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/nfs/home/kshrestha/Desktop/CS 482/cs482-fall2018/1-tictactoe/src/tictac_turnin.cc" -o CMakeFiles/tictactoe.dir/src/tictac_turnin.cc.s

CMakeFiles/tictactoe.dir/src/tictac_turnin.cc.o.requires:

.PHONY : CMakeFiles/tictactoe.dir/src/tictac_turnin.cc.o.requires

CMakeFiles/tictactoe.dir/src/tictac_turnin.cc.o.provides: CMakeFiles/tictactoe.dir/src/tictac_turnin.cc.o.requires
	$(MAKE) -f CMakeFiles/tictactoe.dir/build.make CMakeFiles/tictactoe.dir/src/tictac_turnin.cc.o.provides.build
.PHONY : CMakeFiles/tictactoe.dir/src/tictac_turnin.cc.o.provides

CMakeFiles/tictactoe.dir/src/tictac_turnin.cc.o.provides.build: CMakeFiles/tictactoe.dir/src/tictac_turnin.cc.o


# Object files for target tictactoe
tictactoe_OBJECTS = \
"CMakeFiles/tictactoe.dir/src/tictac.cc.o" \
"CMakeFiles/tictactoe.dir/src/tictac_support.cc.o" \
"CMakeFiles/tictactoe.dir/src/tictac_turnin.cc.o"

# External object files for target tictactoe
tictactoe_EXTERNAL_OBJECTS =

tictactoe: CMakeFiles/tictactoe.dir/src/tictac.cc.o
tictactoe: CMakeFiles/tictactoe.dir/src/tictac_support.cc.o
tictactoe: CMakeFiles/tictactoe.dir/src/tictac_turnin.cc.o
tictactoe: CMakeFiles/tictactoe.dir/build.make
tictactoe: CMakeFiles/tictactoe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/nfs/home/kshrestha/Desktop/CS 482/cs482-fall2018/1-tictactoe/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable tictactoe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tictactoe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tictactoe.dir/build: tictactoe

.PHONY : CMakeFiles/tictactoe.dir/build

CMakeFiles/tictactoe.dir/requires: CMakeFiles/tictactoe.dir/src/tictac.cc.o.requires
CMakeFiles/tictactoe.dir/requires: CMakeFiles/tictactoe.dir/src/tictac_support.cc.o.requires
CMakeFiles/tictactoe.dir/requires: CMakeFiles/tictactoe.dir/src/tictac_turnin.cc.o.requires

.PHONY : CMakeFiles/tictactoe.dir/requires

CMakeFiles/tictactoe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tictactoe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tictactoe.dir/clean

CMakeFiles/tictactoe.dir/depend:
	cd "/nfs/home/kshrestha/Desktop/CS 482/cs482-fall2018/1-tictactoe/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/nfs/home/kshrestha/Desktop/CS 482/cs482-fall2018/1-tictactoe" "/nfs/home/kshrestha/Desktop/CS 482/cs482-fall2018/1-tictactoe" "/nfs/home/kshrestha/Desktop/CS 482/cs482-fall2018/1-tictactoe/build" "/nfs/home/kshrestha/Desktop/CS 482/cs482-fall2018/1-tictactoe/build" "/nfs/home/kshrestha/Desktop/CS 482/cs482-fall2018/1-tictactoe/build/CMakeFiles/tictactoe.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/tictactoe.dir/depend

