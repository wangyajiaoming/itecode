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
include sdk/driver/nor/it970/CMakeFiles/nor.dir/depend.make

# Include the progress variables for this target.
include sdk/driver/nor/it970/CMakeFiles/nor.dir/progress.make

# Include the compile flags for this target's objects.
include sdk/driver/nor/it970/CMakeFiles/nor.dir/flags.make

sdk/driver/nor/it970/CMakeFiles/nor.dir/nor.c.obj: sdk/driver/nor/it970/CMakeFiles/nor.dir/flags.make
sdk/driver/nor/it970/CMakeFiles/nor.dir/nor.c.obj: ../../../sdk/driver/nor/it970/nor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object sdk/driver/nor/it970/CMakeFiles/nor.dir/nor.c.obj"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/nor/it970 && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nor.dir/nor.c.obj   -c C:/ite_sdk/sdk/driver/nor/it970/nor.c

sdk/driver/nor/it970/CMakeFiles/nor.dir/nor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nor.dir/nor.c.i"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/nor/it970 && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/ite_sdk/sdk/driver/nor/it970/nor.c > CMakeFiles/nor.dir/nor.c.i

sdk/driver/nor/it970/CMakeFiles/nor.dir/nor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nor.dir/nor.c.s"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/nor/it970 && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/ite_sdk/sdk/driver/nor/it970/nor.c -o CMakeFiles/nor.dir/nor.c.s

# Object files for target nor
nor_OBJECTS = \
"CMakeFiles/nor.dir/nor.c.obj"

# External object files for target nor
nor_EXTERNAL_OBJECTS =

lib/fa626/libnor.a: sdk/driver/nor/it970/CMakeFiles/nor.dir/nor.c.obj
lib/fa626/libnor.a: sdk/driver/nor/it970/CMakeFiles/nor.dir/build.make
lib/fa626/libnor.a: sdk/driver/nor/it970/CMakeFiles/nor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library ../../../../lib/fa626/libnor.a"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/nor/it970 && $(CMAKE_COMMAND) -P CMakeFiles/nor.dir/cmake_clean_target.cmake
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/nor/it970 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sdk/driver/nor/it970/CMakeFiles/nor.dir/build: lib/fa626/libnor.a

.PHONY : sdk/driver/nor/it970/CMakeFiles/nor.dir/build

sdk/driver/nor/it970/CMakeFiles/nor.dir/clean:
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/nor/it970 && $(CMAKE_COMMAND) -P CMakeFiles/nor.dir/cmake_clean.cmake
.PHONY : sdk/driver/nor/it970/CMakeFiles/nor.dir/clean

sdk/driver/nor/it970/CMakeFiles/nor.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/ite_sdk C:/ite_sdk/sdk/driver/nor/it970 C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/nor/it970 C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/nor/it970/CMakeFiles/nor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sdk/driver/nor/it970/CMakeFiles/nor.dir/depend

