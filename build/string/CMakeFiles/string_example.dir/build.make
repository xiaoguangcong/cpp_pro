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
CMAKE_SOURCE_DIR = /mnt/c/Users/xgc/Desktop/cpp_pro

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/xgc/Desktop/cpp_pro/build

# Include any dependencies generated for this target.
include string/CMakeFiles/string_example.dir/depend.make

# Include the progress variables for this target.
include string/CMakeFiles/string_example.dir/progress.make

# Include the compile flags for this target's objects.
include string/CMakeFiles/string_example.dir/flags.make

string/CMakeFiles/string_example.dir/main.cpp.o: string/CMakeFiles/string_example.dir/flags.make
string/CMakeFiles/string_example.dir/main.cpp.o: ../string/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/xgc/Desktop/cpp_pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object string/CMakeFiles/string_example.dir/main.cpp.o"
	cd /mnt/c/Users/xgc/Desktop/cpp_pro/build/string && /usr/bin/g++-5   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/string_example.dir/main.cpp.o -c /mnt/c/Users/xgc/Desktop/cpp_pro/string/main.cpp

string/CMakeFiles/string_example.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/string_example.dir/main.cpp.i"
	cd /mnt/c/Users/xgc/Desktop/cpp_pro/build/string && /usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/xgc/Desktop/cpp_pro/string/main.cpp > CMakeFiles/string_example.dir/main.cpp.i

string/CMakeFiles/string_example.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/string_example.dir/main.cpp.s"
	cd /mnt/c/Users/xgc/Desktop/cpp_pro/build/string && /usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/xgc/Desktop/cpp_pro/string/main.cpp -o CMakeFiles/string_example.dir/main.cpp.s

string/CMakeFiles/string_example.dir/main.cpp.o.requires:

.PHONY : string/CMakeFiles/string_example.dir/main.cpp.o.requires

string/CMakeFiles/string_example.dir/main.cpp.o.provides: string/CMakeFiles/string_example.dir/main.cpp.o.requires
	$(MAKE) -f string/CMakeFiles/string_example.dir/build.make string/CMakeFiles/string_example.dir/main.cpp.o.provides.build
.PHONY : string/CMakeFiles/string_example.dir/main.cpp.o.provides

string/CMakeFiles/string_example.dir/main.cpp.o.provides.build: string/CMakeFiles/string_example.dir/main.cpp.o


string/CMakeFiles/string_example.dir/string.cpp.o: string/CMakeFiles/string_example.dir/flags.make
string/CMakeFiles/string_example.dir/string.cpp.o: ../string/string.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/xgc/Desktop/cpp_pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object string/CMakeFiles/string_example.dir/string.cpp.o"
	cd /mnt/c/Users/xgc/Desktop/cpp_pro/build/string && /usr/bin/g++-5   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/string_example.dir/string.cpp.o -c /mnt/c/Users/xgc/Desktop/cpp_pro/string/string.cpp

string/CMakeFiles/string_example.dir/string.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/string_example.dir/string.cpp.i"
	cd /mnt/c/Users/xgc/Desktop/cpp_pro/build/string && /usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/xgc/Desktop/cpp_pro/string/string.cpp > CMakeFiles/string_example.dir/string.cpp.i

string/CMakeFiles/string_example.dir/string.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/string_example.dir/string.cpp.s"
	cd /mnt/c/Users/xgc/Desktop/cpp_pro/build/string && /usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/xgc/Desktop/cpp_pro/string/string.cpp -o CMakeFiles/string_example.dir/string.cpp.s

string/CMakeFiles/string_example.dir/string.cpp.o.requires:

.PHONY : string/CMakeFiles/string_example.dir/string.cpp.o.requires

string/CMakeFiles/string_example.dir/string.cpp.o.provides: string/CMakeFiles/string_example.dir/string.cpp.o.requires
	$(MAKE) -f string/CMakeFiles/string_example.dir/build.make string/CMakeFiles/string_example.dir/string.cpp.o.provides.build
.PHONY : string/CMakeFiles/string_example.dir/string.cpp.o.provides

string/CMakeFiles/string_example.dir/string.cpp.o.provides.build: string/CMakeFiles/string_example.dir/string.cpp.o


# Object files for target string_example
string_example_OBJECTS = \
"CMakeFiles/string_example.dir/main.cpp.o" \
"CMakeFiles/string_example.dir/string.cpp.o"

# External object files for target string_example
string_example_EXTERNAL_OBJECTS =

../bin/string_example: string/CMakeFiles/string_example.dir/main.cpp.o
../bin/string_example: string/CMakeFiles/string_example.dir/string.cpp.o
../bin/string_example: string/CMakeFiles/string_example.dir/build.make
../bin/string_example: string/CMakeFiles/string_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/xgc/Desktop/cpp_pro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../bin/string_example"
	cd /mnt/c/Users/xgc/Desktop/cpp_pro/build/string && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/string_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
string/CMakeFiles/string_example.dir/build: ../bin/string_example

.PHONY : string/CMakeFiles/string_example.dir/build

string/CMakeFiles/string_example.dir/requires: string/CMakeFiles/string_example.dir/main.cpp.o.requires
string/CMakeFiles/string_example.dir/requires: string/CMakeFiles/string_example.dir/string.cpp.o.requires

.PHONY : string/CMakeFiles/string_example.dir/requires

string/CMakeFiles/string_example.dir/clean:
	cd /mnt/c/Users/xgc/Desktop/cpp_pro/build/string && $(CMAKE_COMMAND) -P CMakeFiles/string_example.dir/cmake_clean.cmake
.PHONY : string/CMakeFiles/string_example.dir/clean

string/CMakeFiles/string_example.dir/depend:
	cd /mnt/c/Users/xgc/Desktop/cpp_pro/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/xgc/Desktop/cpp_pro /mnt/c/Users/xgc/Desktop/cpp_pro/string /mnt/c/Users/xgc/Desktop/cpp_pro/build /mnt/c/Users/xgc/Desktop/cpp_pro/build/string /mnt/c/Users/xgc/Desktop/cpp_pro/build/string/CMakeFiles/string_example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : string/CMakeFiles/string_example.dir/depend

