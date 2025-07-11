# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/lukas/Desktop/cpp_ethlib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lukas/Desktop/cpp_ethlib/build

# Include any dependencies generated for this target.
include rpc/CMakeFiles/rpc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include rpc/CMakeFiles/rpc.dir/compiler_depend.make

# Include the progress variables for this target.
include rpc/CMakeFiles/rpc.dir/progress.make

# Include the compile flags for this target's objects.
include rpc/CMakeFiles/rpc.dir/flags.make

rpc/CMakeFiles/rpc.dir/EthereumRpcClient.cpp.o: rpc/CMakeFiles/rpc.dir/flags.make
rpc/CMakeFiles/rpc.dir/EthereumRpcClient.cpp.o: /home/lukas/Desktop/cpp_ethlib/rpc/EthereumRpcClient.cpp
rpc/CMakeFiles/rpc.dir/EthereumRpcClient.cpp.o: rpc/CMakeFiles/rpc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/lukas/Desktop/cpp_ethlib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object rpc/CMakeFiles/rpc.dir/EthereumRpcClient.cpp.o"
	cd /home/lukas/Desktop/cpp_ethlib/build/rpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT rpc/CMakeFiles/rpc.dir/EthereumRpcClient.cpp.o -MF CMakeFiles/rpc.dir/EthereumRpcClient.cpp.o.d -o CMakeFiles/rpc.dir/EthereumRpcClient.cpp.o -c /home/lukas/Desktop/cpp_ethlib/rpc/EthereumRpcClient.cpp

rpc/CMakeFiles/rpc.dir/EthereumRpcClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/rpc.dir/EthereumRpcClient.cpp.i"
	cd /home/lukas/Desktop/cpp_ethlib/build/rpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukas/Desktop/cpp_ethlib/rpc/EthereumRpcClient.cpp > CMakeFiles/rpc.dir/EthereumRpcClient.cpp.i

rpc/CMakeFiles/rpc.dir/EthereumRpcClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/rpc.dir/EthereumRpcClient.cpp.s"
	cd /home/lukas/Desktop/cpp_ethlib/build/rpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukas/Desktop/cpp_ethlib/rpc/EthereumRpcClient.cpp -o CMakeFiles/rpc.dir/EthereumRpcClient.cpp.s

# Object files for target rpc
rpc_OBJECTS = \
"CMakeFiles/rpc.dir/EthereumRpcClient.cpp.o"

# External object files for target rpc
rpc_EXTERNAL_OBJECTS =

rpc/librpc.a: rpc/CMakeFiles/rpc.dir/EthereumRpcClient.cpp.o
rpc/librpc.a: rpc/CMakeFiles/rpc.dir/build.make
rpc/librpc.a: rpc/CMakeFiles/rpc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/lukas/Desktop/cpp_ethlib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library librpc.a"
	cd /home/lukas/Desktop/cpp_ethlib/build/rpc && $(CMAKE_COMMAND) -P CMakeFiles/rpc.dir/cmake_clean_target.cmake
	cd /home/lukas/Desktop/cpp_ethlib/build/rpc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rpc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
rpc/CMakeFiles/rpc.dir/build: rpc/librpc.a
.PHONY : rpc/CMakeFiles/rpc.dir/build

rpc/CMakeFiles/rpc.dir/clean:
	cd /home/lukas/Desktop/cpp_ethlib/build/rpc && $(CMAKE_COMMAND) -P CMakeFiles/rpc.dir/cmake_clean.cmake
.PHONY : rpc/CMakeFiles/rpc.dir/clean

rpc/CMakeFiles/rpc.dir/depend:
	cd /home/lukas/Desktop/cpp_ethlib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lukas/Desktop/cpp_ethlib /home/lukas/Desktop/cpp_ethlib/rpc /home/lukas/Desktop/cpp_ethlib/build /home/lukas/Desktop/cpp_ethlib/build/rpc /home/lukas/Desktop/cpp_ethlib/build/rpc/CMakeFiles/rpc.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : rpc/CMakeFiles/rpc.dir/depend

