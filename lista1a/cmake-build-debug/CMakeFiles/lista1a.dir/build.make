# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\joaov\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\203.7148.70\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\joaov\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\203.7148.70\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\CPA\lista1a

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CPA\lista1a\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lista1a.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lista1a.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lista1a.dir/flags.make

CMakeFiles/lista1a.dir/main.cpp.obj: CMakeFiles/lista1a.dir/flags.make
CMakeFiles/lista1a.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CPA\lista1a\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lista1a.dir/main.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lista1a.dir\main.cpp.obj -c D:\CPA\lista1a\main.cpp

CMakeFiles/lista1a.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lista1a.dir/main.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CPA\lista1a\main.cpp > CMakeFiles\lista1a.dir\main.cpp.i

CMakeFiles/lista1a.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lista1a.dir/main.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CPA\lista1a\main.cpp -o CMakeFiles\lista1a.dir\main.cpp.s

# Object files for target lista1a
lista1a_OBJECTS = \
"CMakeFiles/lista1a.dir/main.cpp.obj"

# External object files for target lista1a
lista1a_EXTERNAL_OBJECTS =

lista1a.exe: CMakeFiles/lista1a.dir/main.cpp.obj
lista1a.exe: CMakeFiles/lista1a.dir/build.make
lista1a.exe: CMakeFiles/lista1a.dir/linklibs.rsp
lista1a.exe: CMakeFiles/lista1a.dir/objects1.rsp
lista1a.exe: CMakeFiles/lista1a.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CPA\lista1a\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lista1a.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lista1a.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lista1a.dir/build: lista1a.exe

.PHONY : CMakeFiles/lista1a.dir/build

CMakeFiles/lista1a.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lista1a.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lista1a.dir/clean

CMakeFiles/lista1a.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CPA\lista1a D:\CPA\lista1a D:\CPA\lista1a\cmake-build-debug D:\CPA\lista1a\cmake-build-debug D:\CPA\lista1a\cmake-build-debug\CMakeFiles\lista1a.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lista1a.dir/depend

