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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/autonav/Desktop/frame/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/autonav/Desktop/frame/build

# Include any dependencies generated for this target.
include Main/CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Main/CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include Main/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include Main/CMakeFiles/main.dir/flags.make

Main/CMakeFiles/main.dir/src/main.cpp.o: Main/CMakeFiles/main.dir/flags.make
Main/CMakeFiles/main.dir/src/main.cpp.o: /home/autonav/Desktop/frame/src/Main/src/main.cpp
Main/CMakeFiles/main.dir/src/main.cpp.o: Main/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/autonav/Desktop/frame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Main/CMakeFiles/main.dir/src/main.cpp.o"
	cd /home/autonav/Desktop/frame/build/Main && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Main/CMakeFiles/main.dir/src/main.cpp.o -MF CMakeFiles/main.dir/src/main.cpp.o.d -o CMakeFiles/main.dir/src/main.cpp.o -c /home/autonav/Desktop/frame/src/Main/src/main.cpp

Main/CMakeFiles/main.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/main.cpp.i"
	cd /home/autonav/Desktop/frame/build/Main && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/autonav/Desktop/frame/src/Main/src/main.cpp > CMakeFiles/main.dir/src/main.cpp.i

Main/CMakeFiles/main.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/main.cpp.s"
	cd /home/autonav/Desktop/frame/build/Main && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/autonav/Desktop/frame/src/Main/src/main.cpp -o CMakeFiles/main.dir/src/main.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/src/main.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

/home/autonav/Desktop/frame/devel/lib/Main/main: Main/CMakeFiles/main.dir/src/main.cpp.o
/home/autonav/Desktop/frame/devel/lib/Main/main: Main/CMakeFiles/main.dir/build.make
/home/autonav/Desktop/frame/devel/lib/Main/main: /home/autonav/Desktop/frame/devel/lib/libmyHeader.so
/home/autonav/Desktop/frame/devel/lib/Main/main: /opt/ros/noetic/lib/libroscpp.so
/home/autonav/Desktop/frame/devel/lib/Main/main: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/autonav/Desktop/frame/devel/lib/Main/main: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.71.0
/home/autonav/Desktop/frame/devel/lib/Main/main: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.71.0
/home/autonav/Desktop/frame/devel/lib/Main/main: /opt/ros/noetic/lib/librosconsole.so
/home/autonav/Desktop/frame/devel/lib/Main/main: /opt/ros/noetic/lib/librosconsole_log4cxx.so
/home/autonav/Desktop/frame/devel/lib/Main/main: /opt/ros/noetic/lib/librosconsole_backend_interface.so
/home/autonav/Desktop/frame/devel/lib/Main/main: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/autonav/Desktop/frame/devel/lib/Main/main: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.71.0
/home/autonav/Desktop/frame/devel/lib/Main/main: /opt/ros/noetic/lib/libxmlrpcpp.so
/home/autonav/Desktop/frame/devel/lib/Main/main: /opt/ros/noetic/lib/libroscpp_serialization.so
/home/autonav/Desktop/frame/devel/lib/Main/main: /opt/ros/noetic/lib/librostime.so
/home/autonav/Desktop/frame/devel/lib/Main/main: /usr/lib/x86_64-linux-gnu/libboost_date_time.so.1.71.0
/home/autonav/Desktop/frame/devel/lib/Main/main: /opt/ros/noetic/lib/libcpp_common.so
/home/autonav/Desktop/frame/devel/lib/Main/main: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.71.0
/home/autonav/Desktop/frame/devel/lib/Main/main: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
/home/autonav/Desktop/frame/devel/lib/Main/main: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/autonav/Desktop/frame/devel/lib/Main/main: Main/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/autonav/Desktop/frame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/autonav/Desktop/frame/devel/lib/Main/main"
	cd /home/autonav/Desktop/frame/build/Main && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Main/CMakeFiles/main.dir/build: /home/autonav/Desktop/frame/devel/lib/Main/main
.PHONY : Main/CMakeFiles/main.dir/build

Main/CMakeFiles/main.dir/clean:
	cd /home/autonav/Desktop/frame/build/Main && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : Main/CMakeFiles/main.dir/clean

Main/CMakeFiles/main.dir/depend:
	cd /home/autonav/Desktop/frame/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/autonav/Desktop/frame/src /home/autonav/Desktop/frame/src/Main /home/autonav/Desktop/frame/build /home/autonav/Desktop/frame/build/Main /home/autonav/Desktop/frame/build/Main/CMakeFiles/main.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : Main/CMakeFiles/main.dir/depend

