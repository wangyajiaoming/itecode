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
include sdk/share/fat/CMakeFiles/fat_msc.dir/depend.make

# Include the progress variables for this target.
include sdk/share/fat/CMakeFiles/fat_msc.dir/progress.make

# Include the compile flags for this target's objects.
include sdk/share/fat/CMakeFiles/fat_msc.dir/flags.make

sdk/share/fat/CMakeFiles/fat_msc.dir/msc/ite_msc_fat.c.obj: sdk/share/fat/CMakeFiles/fat_msc.dir/flags.make
sdk/share/fat/CMakeFiles/fat_msc.dir/msc/ite_msc_fat.c.obj: ../../../sdk/share/fat/msc/ite_msc_fat.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object sdk/share/fat/CMakeFiles/fat_msc.dir/msc/ite_msc_fat.c.obj"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/fat && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fat_msc.dir/msc/ite_msc_fat.c.obj   -c C:/ite_sdk/sdk/share/fat/msc/ite_msc_fat.c

sdk/share/fat/CMakeFiles/fat_msc.dir/msc/ite_msc_fat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fat_msc.dir/msc/ite_msc_fat.c.i"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/fat && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/ite_sdk/sdk/share/fat/msc/ite_msc_fat.c > CMakeFiles/fat_msc.dir/msc/ite_msc_fat.c.i

sdk/share/fat/CMakeFiles/fat_msc.dir/msc/ite_msc_fat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fat_msc.dir/msc/ite_msc_fat.c.s"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/fat && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/ite_sdk/sdk/share/fat/msc/ite_msc_fat.c -o CMakeFiles/fat_msc.dir/msc/ite_msc_fat.c.s

# Object files for target fat_msc
fat_msc_OBJECTS = \
"CMakeFiles/fat_msc.dir/msc/ite_msc_fat.c.obj"

# External object files for target fat_msc
fat_msc_EXTERNAL_OBJECTS =

lib/fa626/libfat_msc.a: sdk/share/fat/CMakeFiles/fat_msc.dir/msc/ite_msc_fat.c.obj
lib/fa626/libfat_msc.a: sdk/share/fat/CMakeFiles/fat_msc.dir/build.make
lib/fa626/libfat_msc.a: sdk/share/fat/CMakeFiles/fat_msc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library ../../../lib/fa626/libfat_msc.a"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/fat && $(CMAKE_COMMAND) -P CMakeFiles/fat_msc.dir/cmake_clean_target.cmake
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/fat && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fat_msc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sdk/share/fat/CMakeFiles/fat_msc.dir/build: lib/fa626/libfat_msc.a

.PHONY : sdk/share/fat/CMakeFiles/fat_msc.dir/build

sdk/share/fat/CMakeFiles/fat_msc.dir/clean:
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/fat && $(CMAKE_COMMAND) -P CMakeFiles/fat_msc.dir/cmake_clean.cmake
.PHONY : sdk/share/fat/CMakeFiles/fat_msc.dir/clean

sdk/share/fat/CMakeFiles/fat_msc.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/ite_sdk C:/ite_sdk/sdk/share/fat C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/fat C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/fat/CMakeFiles/fat_msc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sdk/share/fat/CMakeFiles/fat_msc.dir/depend

