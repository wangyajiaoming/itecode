# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = C:/ite_sdk/tool/bin/cmake.exe

# The command to remove a file.
RM = C:/ite_sdk/tool/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/ite_sdk

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr

# Include any dependencies generated for this target.
include sdk/share/redblack/CMakeFiles/redblack.dir/depend.make

# Include the progress variables for this target.
include sdk/share/redblack/CMakeFiles/redblack.dir/progress.make

# Include the compile flags for this target's objects.
include sdk/share/redblack/CMakeFiles/redblack.dir/flags.make

sdk/share/redblack/CMakeFiles/redblack.dir/redblack.c.obj: sdk/share/redblack/CMakeFiles/redblack.dir/flags.make
sdk/share/redblack/CMakeFiles/redblack.dir/redblack.c.obj: ../../../sdk/share/redblack/redblack.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object sdk/share/redblack/CMakeFiles/redblack.dir/redblack.c.obj"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/redblack && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/redblack.dir/redblack.c.obj   -c C:/ite_sdk/sdk/share/redblack/redblack.c

sdk/share/redblack/CMakeFiles/redblack.dir/redblack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/redblack.dir/redblack.c.i"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/redblack && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/ite_sdk/sdk/share/redblack/redblack.c > CMakeFiles/redblack.dir/redblack.c.i

sdk/share/redblack/CMakeFiles/redblack.dir/redblack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/redblack.dir/redblack.c.s"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/redblack && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/ite_sdk/sdk/share/redblack/redblack.c -o CMakeFiles/redblack.dir/redblack.c.s

# Object files for target redblack
redblack_OBJECTS = \
"CMakeFiles/redblack.dir/redblack.c.obj"

# External object files for target redblack
redblack_EXTERNAL_OBJECTS =

lib/fa626/libredblack.a: sdk/share/redblack/CMakeFiles/redblack.dir/redblack.c.obj
lib/fa626/libredblack.a: sdk/share/redblack/CMakeFiles/redblack.dir/build.make
lib/fa626/libredblack.a: sdk/share/redblack/CMakeFiles/redblack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library ../../../lib/fa626/libredblack.a"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/redblack && $(CMAKE_COMMAND) -P CMakeFiles/redblack.dir/cmake_clean_target.cmake
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/redblack && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/redblack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sdk/share/redblack/CMakeFiles/redblack.dir/build: lib/fa626/libredblack.a

.PHONY : sdk/share/redblack/CMakeFiles/redblack.dir/build

sdk/share/redblack/CMakeFiles/redblack.dir/clean:
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/redblack && $(CMAKE_COMMAND) -P CMakeFiles/redblack.dir/cmake_clean.cmake
.PHONY : sdk/share/redblack/CMakeFiles/redblack.dir/clean

sdk/share/redblack/CMakeFiles/redblack.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/ite_sdk C:/ite_sdk/sdk/share/redblack C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/redblack C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/redblack/CMakeFiles/redblack.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sdk/share/redblack/CMakeFiles/redblack.dir/depend

