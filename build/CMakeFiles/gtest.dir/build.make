# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bmere/Repositories/CPP-Projects

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bmere/Repositories/CPP-Projects/build

# Include any dependencies generated for this target.
include CMakeFiles/gtest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/gtest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gtest.dir/flags.make

CMakeFiles/gtest.dir/tests/gtest.cpp.o: CMakeFiles/gtest.dir/flags.make
CMakeFiles/gtest.dir/tests/gtest.cpp.o: ../tests/gtest.cpp
CMakeFiles/gtest.dir/tests/gtest.cpp.o: CMakeFiles/gtest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bmere/Repositories/CPP-Projects/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gtest.dir/tests/gtest.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gtest.dir/tests/gtest.cpp.o -MF CMakeFiles/gtest.dir/tests/gtest.cpp.o.d -o CMakeFiles/gtest.dir/tests/gtest.cpp.o -c /home/bmere/Repositories/CPP-Projects/tests/gtest.cpp

CMakeFiles/gtest.dir/tests/gtest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/tests/gtest.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bmere/Repositories/CPP-Projects/tests/gtest.cpp > CMakeFiles/gtest.dir/tests/gtest.cpp.i

CMakeFiles/gtest.dir/tests/gtest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/tests/gtest.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bmere/Repositories/CPP-Projects/tests/gtest.cpp -o CMakeFiles/gtest.dir/tests/gtest.cpp.s

CMakeFiles/gtest.dir/src/Queue.cpp.o: CMakeFiles/gtest.dir/flags.make
CMakeFiles/gtest.dir/src/Queue.cpp.o: ../src/Queue.cpp
CMakeFiles/gtest.dir/src/Queue.cpp.o: CMakeFiles/gtest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bmere/Repositories/CPP-Projects/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/gtest.dir/src/Queue.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gtest.dir/src/Queue.cpp.o -MF CMakeFiles/gtest.dir/src/Queue.cpp.o.d -o CMakeFiles/gtest.dir/src/Queue.cpp.o -c /home/bmere/Repositories/CPP-Projects/src/Queue.cpp

CMakeFiles/gtest.dir/src/Queue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/Queue.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bmere/Repositories/CPP-Projects/src/Queue.cpp > CMakeFiles/gtest.dir/src/Queue.cpp.i

CMakeFiles/gtest.dir/src/Queue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/Queue.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bmere/Repositories/CPP-Projects/src/Queue.cpp -o CMakeFiles/gtest.dir/src/Queue.cpp.s

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/tests/gtest.cpp.o" \
"CMakeFiles/gtest.dir/src/Queue.cpp.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

bin/gtest: CMakeFiles/gtest.dir/tests/gtest.cpp.o
bin/gtest: CMakeFiles/gtest.dir/src/Queue.cpp.o
bin/gtest: CMakeFiles/gtest.dir/build.make
bin/gtest: libDataStructures.a
bin/gtest: /usr/lib/x86_64-linux-gnu/libgtest.a
bin/gtest: /usr/lib/x86_64-linux-gnu/libgtest_main.a
bin/gtest: /usr/lib/x86_64-linux-gnu/libgtest.a
bin/gtest: CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bmere/Repositories/CPP-Projects/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable bin/gtest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gtest.dir/build: bin/gtest
.PHONY : CMakeFiles/gtest.dir/build

CMakeFiles/gtest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gtest.dir/clean

CMakeFiles/gtest.dir/depend:
	cd /home/bmere/Repositories/CPP-Projects/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bmere/Repositories/CPP-Projects /home/bmere/Repositories/CPP-Projects /home/bmere/Repositories/CPP-Projects/build /home/bmere/Repositories/CPP-Projects/build /home/bmere/Repositories/CPP-Projects/build/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gtest.dir/depend
