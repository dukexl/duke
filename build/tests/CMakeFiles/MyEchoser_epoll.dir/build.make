# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/xuli/build/cmake-3.17.1-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/xuli/build/cmake-3.17.1-Linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/hgfs/learngit/xl_public

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/hgfs/learngit/xl_public/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/MyEchoser_epoll.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/MyEchoser_epoll.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/MyEchoser_epoll.dir/flags.make

tests/CMakeFiles/MyEchoser_epoll.dir/echoser_epoll.cpp.o: tests/CMakeFiles/MyEchoser_epoll.dir/flags.make
tests/CMakeFiles/MyEchoser_epoll.dir/echoser_epoll.cpp.o: ../tests/echoser_epoll.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/learngit/xl_public/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/MyEchoser_epoll.dir/echoser_epoll.cpp.o"
	cd /mnt/hgfs/learngit/xl_public/build/tests && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyEchoser_epoll.dir/echoser_epoll.cpp.o -c /mnt/hgfs/learngit/xl_public/tests/echoser_epoll.cpp

tests/CMakeFiles/MyEchoser_epoll.dir/echoser_epoll.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyEchoser_epoll.dir/echoser_epoll.cpp.i"
	cd /mnt/hgfs/learngit/xl_public/build/tests && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/learngit/xl_public/tests/echoser_epoll.cpp > CMakeFiles/MyEchoser_epoll.dir/echoser_epoll.cpp.i

tests/CMakeFiles/MyEchoser_epoll.dir/echoser_epoll.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyEchoser_epoll.dir/echoser_epoll.cpp.s"
	cd /mnt/hgfs/learngit/xl_public/build/tests && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/learngit/xl_public/tests/echoser_epoll.cpp -o CMakeFiles/MyEchoser_epoll.dir/echoser_epoll.cpp.s

# Object files for target MyEchoser_epoll
MyEchoser_epoll_OBJECTS = \
"CMakeFiles/MyEchoser_epoll.dir/echoser_epoll.cpp.o"

# External object files for target MyEchoser_epoll
MyEchoser_epoll_EXTERNAL_OBJECTS =

bin/MyEchoser_epoll: tests/CMakeFiles/MyEchoser_epoll.dir/echoser_epoll.cpp.o
bin/MyEchoser_epoll: tests/CMakeFiles/MyEchoser_epoll.dir/build.make
bin/MyEchoser_epoll: tests/CMakeFiles/MyEchoser_epoll.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/hgfs/learngit/xl_public/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/MyEchoser_epoll"
	cd /mnt/hgfs/learngit/xl_public/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyEchoser_epoll.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/MyEchoser_epoll.dir/build: bin/MyEchoser_epoll

.PHONY : tests/CMakeFiles/MyEchoser_epoll.dir/build

tests/CMakeFiles/MyEchoser_epoll.dir/clean:
	cd /mnt/hgfs/learngit/xl_public/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/MyEchoser_epoll.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/MyEchoser_epoll.dir/clean

tests/CMakeFiles/MyEchoser_epoll.dir/depend:
	cd /mnt/hgfs/learngit/xl_public/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/hgfs/learngit/xl_public /mnt/hgfs/learngit/xl_public/tests /mnt/hgfs/learngit/xl_public/build /mnt/hgfs/learngit/xl_public/build/tests /mnt/hgfs/learngit/xl_public/build/tests/CMakeFiles/MyEchoser_epoll.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/MyEchoser_epoll.dir/depend

