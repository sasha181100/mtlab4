# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Kent\CLionProjects\mtlab4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Kent\CLionProjects\mtlab4\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/mtlab4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mtlab4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mtlab4.dir/flags.make

CMakeFiles/mtlab4.dir/main.cpp.obj: CMakeFiles/mtlab4.dir/flags.make
CMakeFiles/mtlab4.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Kent\CLionProjects\mtlab4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mtlab4.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\mtlab4.dir\main.cpp.obj -c C:\Users\Kent\CLionProjects\mtlab4\main.cpp

CMakeFiles/mtlab4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mtlab4.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Kent\CLionProjects\mtlab4\main.cpp > CMakeFiles\mtlab4.dir\main.cpp.i

CMakeFiles/mtlab4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mtlab4.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Kent\CLionProjects\mtlab4\main.cpp -o CMakeFiles\mtlab4.dir\main.cpp.s

CMakeFiles/mtlab4.dir/gen/output.cpp.obj: CMakeFiles/mtlab4.dir/flags.make
CMakeFiles/mtlab4.dir/gen/output.cpp.obj: ../gen/output.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Kent\CLionProjects\mtlab4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mtlab4.dir/gen/output.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\mtlab4.dir\gen\output.cpp.obj -c C:\Users\Kent\CLionProjects\mtlab4\gen\output.cpp

CMakeFiles/mtlab4.dir/gen/output.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mtlab4.dir/gen/output.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Kent\CLionProjects\mtlab4\gen\output.cpp > CMakeFiles\mtlab4.dir\gen\output.cpp.i

CMakeFiles/mtlab4.dir/gen/output.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mtlab4.dir/gen/output.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Kent\CLionProjects\mtlab4\gen\output.cpp -o CMakeFiles\mtlab4.dir\gen\output.cpp.s

# Object files for target mtlab4
mtlab4_OBJECTS = \
"CMakeFiles/mtlab4.dir/main.cpp.obj" \
"CMakeFiles/mtlab4.dir/gen/output.cpp.obj"

# External object files for target mtlab4
mtlab4_EXTERNAL_OBJECTS =

mtlab4.exe: CMakeFiles/mtlab4.dir/main.cpp.obj
mtlab4.exe: CMakeFiles/mtlab4.dir/gen/output.cpp.obj
mtlab4.exe: CMakeFiles/mtlab4.dir/build.make
mtlab4.exe: CMakeFiles/mtlab4.dir/linklibs.rsp
mtlab4.exe: CMakeFiles/mtlab4.dir/objects1.rsp
mtlab4.exe: CMakeFiles/mtlab4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Kent\CLionProjects\mtlab4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable mtlab4.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\mtlab4.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mtlab4.dir/build: mtlab4.exe

.PHONY : CMakeFiles/mtlab4.dir/build

CMakeFiles/mtlab4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\mtlab4.dir\cmake_clean.cmake
.PHONY : CMakeFiles/mtlab4.dir/clean

CMakeFiles/mtlab4.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Kent\CLionProjects\mtlab4 C:\Users\Kent\CLionProjects\mtlab4 C:\Users\Kent\CLionProjects\mtlab4\cmake-build-debug C:\Users\Kent\CLionProjects\mtlab4\cmake-build-debug C:\Users\Kent\CLionProjects\mtlab4\cmake-build-debug\CMakeFiles\mtlab4.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mtlab4.dir/depend
