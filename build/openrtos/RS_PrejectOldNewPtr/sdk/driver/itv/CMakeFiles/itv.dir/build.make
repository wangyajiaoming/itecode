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
include sdk/driver/itv/CMakeFiles/itv.dir/depend.make

# Include the progress variables for this target.
include sdk/driver/itv/CMakeFiles/itv.dir/progress.make

# Include the compile flags for this target's objects.
include sdk/driver/itv/CMakeFiles/itv.dir/flags.make

sdk/driver/itv/CMakeFiles/itv.dir/it970/itv.c.obj: sdk/driver/itv/CMakeFiles/itv.dir/flags.make
sdk/driver/itv/CMakeFiles/itv.dir/it970/itv.c.obj: ../../../sdk/driver/itv/it970/itv.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object sdk/driver/itv/CMakeFiles/itv.dir/it970/itv.c.obj"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itv && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/itv.dir/it970/itv.c.obj   -c C:/ite_sdk/sdk/driver/itv/it970/itv.c

sdk/driver/itv/CMakeFiles/itv.dir/it970/itv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/itv.dir/it970/itv.c.i"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itv && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/ite_sdk/sdk/driver/itv/it970/itv.c > CMakeFiles/itv.dir/it970/itv.c.i

sdk/driver/itv/CMakeFiles/itv.dir/it970/itv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/itv.dir/it970/itv.c.s"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itv && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/ite_sdk/sdk/driver/itv/it970/itv.c -o CMakeFiles/itv.dir/it970/itv.c.s

sdk/driver/itv/CMakeFiles/itv.dir/fc_sync.c.obj: sdk/driver/itv/CMakeFiles/itv.dir/flags.make
sdk/driver/itv/CMakeFiles/itv.dir/fc_sync.c.obj: ../../../sdk/driver/itv/fc_sync.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object sdk/driver/itv/CMakeFiles/itv.dir/fc_sync.c.obj"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itv && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/itv.dir/fc_sync.c.obj   -c C:/ite_sdk/sdk/driver/itv/fc_sync.c

sdk/driver/itv/CMakeFiles/itv.dir/fc_sync.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/itv.dir/fc_sync.c.i"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itv && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/ite_sdk/sdk/driver/itv/fc_sync.c > CMakeFiles/itv.dir/fc_sync.c.i

sdk/driver/itv/CMakeFiles/itv.dir/fc_sync.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/itv.dir/fc_sync.c.s"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itv && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/ite_sdk/sdk/driver/itv/fc_sync.c -o CMakeFiles/itv.dir/fc_sync.c.s

# Object files for target itv
itv_OBJECTS = \
"CMakeFiles/itv.dir/it970/itv.c.obj" \
"CMakeFiles/itv.dir/fc_sync.c.obj"

# External object files for target itv
itv_EXTERNAL_OBJECTS =

lib/fa626/libitv.a: sdk/driver/itv/CMakeFiles/itv.dir/it970/itv.c.obj
lib/fa626/libitv.a: sdk/driver/itv/CMakeFiles/itv.dir/fc_sync.c.obj
lib/fa626/libitv.a: sdk/driver/itv/CMakeFiles/itv.dir/build.make
lib/fa626/libitv.a: sdk/driver/itv/CMakeFiles/itv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library ../../../lib/fa626/libitv.a"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itv && $(CMAKE_COMMAND) -P CMakeFiles/itv.dir/cmake_clean_target.cmake
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itv && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/itv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sdk/driver/itv/CMakeFiles/itv.dir/build: lib/fa626/libitv.a

.PHONY : sdk/driver/itv/CMakeFiles/itv.dir/build

sdk/driver/itv/CMakeFiles/itv.dir/clean:
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itv && $(CMAKE_COMMAND) -P CMakeFiles/itv.dir/cmake_clean.cmake
.PHONY : sdk/driver/itv/CMakeFiles/itv.dir/clean

sdk/driver/itv/CMakeFiles/itv.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/ite_sdk C:/ite_sdk/sdk/driver/itv C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itv C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itv/CMakeFiles/itv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sdk/driver/itv/CMakeFiles/itv.dir/depend

