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
include xlpublic/utility/CMakeFiles/MyBase64_test.dir/depend.make

# Include the progress variables for this target.
include xlpublic/utility/CMakeFiles/MyBase64_test.dir/progress.make

# Include the compile flags for this target's objects.
include xlpublic/utility/CMakeFiles/MyBase64_test.dir/flags.make

xlpublic/utility/CMakeFiles/MyBase64_test.dir/base64.cpp.o: xlpublic/utility/CMakeFiles/MyBase64_test.dir/flags.make
xlpublic/utility/CMakeFiles/MyBase64_test.dir/base64.cpp.o: ../xlpublic/utility/base64.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/learngit/xl_public/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object xlpublic/utility/CMakeFiles/MyBase64_test.dir/base64.cpp.o"
	cd /mnt/hgfs/learngit/xl_public/build/xlpublic/utility && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyBase64_test.dir/base64.cpp.o -c /mnt/hgfs/learngit/xl_public/xlpublic/utility/base64.cpp

xlpublic/utility/CMakeFiles/MyBase64_test.dir/base64.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyBase64_test.dir/base64.cpp.i"
	cd /mnt/hgfs/learngit/xl_public/build/xlpublic/utility && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/learngit/xl_public/xlpublic/utility/base64.cpp > CMakeFiles/MyBase64_test.dir/base64.cpp.i

xlpublic/utility/CMakeFiles/MyBase64_test.dir/base64.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyBase64_test.dir/base64.cpp.s"
	cd /mnt/hgfs/learngit/xl_public/build/xlpublic/utility && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/learngit/xl_public/xlpublic/utility/base64.cpp -o CMakeFiles/MyBase64_test.dir/base64.cpp.s

xlpublic/utility/CMakeFiles/MyBase64_test.dir/test/base64_test.cpp.o: xlpublic/utility/CMakeFiles/MyBase64_test.dir/flags.make
xlpublic/utility/CMakeFiles/MyBase64_test.dir/test/base64_test.cpp.o: ../xlpublic/utility/test/base64_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/learngit/xl_public/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object xlpublic/utility/CMakeFiles/MyBase64_test.dir/test/base64_test.cpp.o"
	cd /mnt/hgfs/learngit/xl_public/build/xlpublic/utility && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyBase64_test.dir/test/base64_test.cpp.o -c /mnt/hgfs/learngit/xl_public/xlpublic/utility/test/base64_test.cpp

xlpublic/utility/CMakeFiles/MyBase64_test.dir/test/base64_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyBase64_test.dir/test/base64_test.cpp.i"
	cd /mnt/hgfs/learngit/xl_public/build/xlpublic/utility && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/learngit/xl_public/xlpublic/utility/test/base64_test.cpp > CMakeFiles/MyBase64_test.dir/test/base64_test.cpp.i

xlpublic/utility/CMakeFiles/MyBase64_test.dir/test/base64_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyBase64_test.dir/test/base64_test.cpp.s"
	cd /mnt/hgfs/learngit/xl_public/build/xlpublic/utility && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/learngit/xl_public/xlpublic/utility/test/base64_test.cpp -o CMakeFiles/MyBase64_test.dir/test/base64_test.cpp.s

# Object files for target MyBase64_test
MyBase64_test_OBJECTS = \
"CMakeFiles/MyBase64_test.dir/base64.cpp.o" \
"CMakeFiles/MyBase64_test.dir/test/base64_test.cpp.o"

# External object files for target MyBase64_test
MyBase64_test_EXTERNAL_OBJECTS =

bin/MyBase64_test: xlpublic/utility/CMakeFiles/MyBase64_test.dir/base64.cpp.o
bin/MyBase64_test: xlpublic/utility/CMakeFiles/MyBase64_test.dir/test/base64_test.cpp.o
bin/MyBase64_test: xlpublic/utility/CMakeFiles/MyBase64_test.dir/build.make
bin/MyBase64_test: xlpublic/utility/CMakeFiles/MyBase64_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/hgfs/learngit/xl_public/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../bin/MyBase64_test"
	cd /mnt/hgfs/learngit/xl_public/build/xlpublic/utility && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyBase64_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
xlpublic/utility/CMakeFiles/MyBase64_test.dir/build: bin/MyBase64_test

.PHONY : xlpublic/utility/CMakeFiles/MyBase64_test.dir/build

xlpublic/utility/CMakeFiles/MyBase64_test.dir/clean:
	cd /mnt/hgfs/learngit/xl_public/build/xlpublic/utility && $(CMAKE_COMMAND) -P CMakeFiles/MyBase64_test.dir/cmake_clean.cmake
.PHONY : xlpublic/utility/CMakeFiles/MyBase64_test.dir/clean

xlpublic/utility/CMakeFiles/MyBase64_test.dir/depend:
	cd /mnt/hgfs/learngit/xl_public/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/hgfs/learngit/xl_public /mnt/hgfs/learngit/xl_public/xlpublic/utility /mnt/hgfs/learngit/xl_public/build /mnt/hgfs/learngit/xl_public/build/xlpublic/utility /mnt/hgfs/learngit/xl_public/build/xlpublic/utility/CMakeFiles/MyBase64_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : xlpublic/utility/CMakeFiles/MyBase64_test.dir/depend

