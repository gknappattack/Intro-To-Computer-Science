# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gregoryknapp/CLionProjects/Pet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gregoryknapp/CLionProjects/Pet/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Pet.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Pet.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Pet.dir/flags.make

CMakeFiles/Pet.dir/main.cpp.o: CMakeFiles/Pet.dir/flags.make
CMakeFiles/Pet.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gregoryknapp/CLionProjects/Pet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Pet.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pet.dir/main.cpp.o -c /Users/gregoryknapp/CLionProjects/Pet/main.cpp

CMakeFiles/Pet.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pet.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gregoryknapp/CLionProjects/Pet/main.cpp > CMakeFiles/Pet.dir/main.cpp.i

CMakeFiles/Pet.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pet.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gregoryknapp/CLionProjects/Pet/main.cpp -o CMakeFiles/Pet.dir/main.cpp.s

# Object files for target Pet
Pet_OBJECTS = \
"CMakeFiles/Pet.dir/main.cpp.o"

# External object files for target Pet
Pet_EXTERNAL_OBJECTS =

Pet: CMakeFiles/Pet.dir/main.cpp.o
Pet: CMakeFiles/Pet.dir/build.make
Pet: CMakeFiles/Pet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gregoryknapp/CLionProjects/Pet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Pet"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Pet.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Pet.dir/build: Pet

.PHONY : CMakeFiles/Pet.dir/build

CMakeFiles/Pet.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Pet.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Pet.dir/clean

CMakeFiles/Pet.dir/depend:
	cd /Users/gregoryknapp/CLionProjects/Pet/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gregoryknapp/CLionProjects/Pet /Users/gregoryknapp/CLionProjects/Pet /Users/gregoryknapp/CLionProjects/Pet/cmake-build-debug /Users/gregoryknapp/CLionProjects/Pet/cmake-build-debug /Users/gregoryknapp/CLionProjects/Pet/cmake-build-debug/CMakeFiles/Pet.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Pet.dir/depend
