# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.2

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
CMAKE_COMMAND = "C:\Program Files (x86)\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\OpenGLLibraries\glewrepo\glew\build\cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\OpenGLLibraries\HolyMolly

# Include any dependencies generated for this target.
include CMakeFiles/visualinfo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/visualinfo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/visualinfo.dir/flags.make

CMakeFiles/visualinfo.dir/C_/OpenGLLibraries/glewrepo/glew/src/visualinfo.obj: CMakeFiles/visualinfo.dir/flags.make
CMakeFiles/visualinfo.dir/C_/OpenGLLibraries/glewrepo/glew/src/visualinfo.obj: CMakeFiles/visualinfo.dir/includes_C.rsp
CMakeFiles/visualinfo.dir/C_/OpenGLLibraries/glewrepo/glew/src/visualinfo.obj: C:/OpenGLLibraries/glewrepo/glew/src/visualinfo.c
	$(CMAKE_COMMAND) -E cmake_progress_report C:\OpenGLLibraries\HolyMolly\CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/visualinfo.dir/C_/OpenGLLibraries/glewrepo/glew/src/visualinfo.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles\visualinfo.dir\C_\OpenGLLibraries\glewrepo\glew\src\visualinfo.obj   -c C:\OpenGLLibraries\glewrepo\glew\src\visualinfo.c

CMakeFiles/visualinfo.dir/C_/OpenGLLibraries/glewrepo/glew/src/visualinfo.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/visualinfo.dir/C_/OpenGLLibraries/glewrepo/glew/src/visualinfo.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_FLAGS) -E C:\OpenGLLibraries\glewrepo\glew\src\visualinfo.c > CMakeFiles\visualinfo.dir\C_\OpenGLLibraries\glewrepo\glew\src\visualinfo.i

CMakeFiles/visualinfo.dir/C_/OpenGLLibraries/glewrepo/glew/src/visualinfo.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/visualinfo.dir/C_/OpenGLLibraries/glewrepo/glew/src/visualinfo.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_FLAGS) -S C:\OpenGLLibraries\glewrepo\glew\src\visualinfo.c -o CMakeFiles\visualinfo.dir\C_\OpenGLLibraries\glewrepo\glew\src\visualinfo.s

CMakeFiles/visualinfo.dir/C_/OpenGLLibraries/glewrepo/glew/src/visualinfo.obj.requires:
.PHONY : CMakeFiles/visualinfo.dir/C_/OpenGLLibraries/glewrepo/glew/src/visualinfo.obj.requires

CMakeFiles/visualinfo.dir/C_/OpenGLLibraries/glewrepo/glew/src/visualinfo.obj.provides: CMakeFiles/visualinfo.dir/C_/OpenGLLibraries/glewrepo/glew/src/visualinfo.obj.requires
	$(MAKE) -f CMakeFiles\visualinfo.dir\build.make CMakeFiles/visualinfo.dir/C_/OpenGLLibraries/glewrepo/glew/src/visualinfo.obj.provides.build
.PHONY : CMakeFiles/visualinfo.dir/C_/OpenGLLibraries/glewrepo/glew/src/visualinfo.obj.provides

CMakeFiles/visualinfo.dir/C_/OpenGLLibraries/glewrepo/glew/src/visualinfo.obj.provides.build: CMakeFiles/visualinfo.dir/C_/OpenGLLibraries/glewrepo/glew/src/visualinfo.obj

# Object files for target visualinfo
visualinfo_OBJECTS = \
"CMakeFiles/visualinfo.dir/C_/OpenGLLibraries/glewrepo/glew/src/visualinfo.obj"

# External object files for target visualinfo
visualinfo_EXTERNAL_OBJECTS =

bin/visualinfo.exe: CMakeFiles/visualinfo.dir/C_/OpenGLLibraries/glewrepo/glew/src/visualinfo.obj
bin/visualinfo.exe: CMakeFiles/visualinfo.dir/build.make
bin/visualinfo.exe: lib/libglew32.dll.a
bin/visualinfo.exe: CMakeFiles/visualinfo.dir/linklibs.rsp
bin/visualinfo.exe: CMakeFiles/visualinfo.dir/objects1.rsp
bin/visualinfo.exe: CMakeFiles/visualinfo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable bin\visualinfo.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\visualinfo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/visualinfo.dir/build: bin/visualinfo.exe
.PHONY : CMakeFiles/visualinfo.dir/build

CMakeFiles/visualinfo.dir/requires: CMakeFiles/visualinfo.dir/C_/OpenGLLibraries/glewrepo/glew/src/visualinfo.obj.requires
.PHONY : CMakeFiles/visualinfo.dir/requires

CMakeFiles/visualinfo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\visualinfo.dir\cmake_clean.cmake
.PHONY : CMakeFiles/visualinfo.dir/clean

CMakeFiles/visualinfo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\OpenGLLibraries\glewrepo\glew\build\cmake C:\OpenGLLibraries\glewrepo\glew\build\cmake C:\OpenGLLibraries\HolyMolly C:\OpenGLLibraries\HolyMolly C:\OpenGLLibraries\HolyMolly\CMakeFiles\visualinfo.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/visualinfo.dir/depend

