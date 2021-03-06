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
include openrtos/boot/CMakeFiles/boot.dir/depend.make

# Include the progress variables for this target.
include openrtos/boot/CMakeFiles/boot.dir/progress.make

# Include the compile flags for this target's objects.
include openrtos/boot/CMakeFiles/boot.dir/flags.make

openrtos/boot/CMakeFiles/boot.dir/init.c.obj: openrtos/boot/CMakeFiles/boot.dir/flags.make
openrtos/boot/CMakeFiles/boot.dir/init.c.obj: ../../../openrtos/boot/init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object openrtos/boot/CMakeFiles/boot.dir/init.c.obj"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/openrtos/boot && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/boot.dir/init.c.obj   -c C:/ite_sdk/openrtos/boot/init.c

openrtos/boot/CMakeFiles/boot.dir/init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/boot.dir/init.c.i"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/openrtos/boot && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/ite_sdk/openrtos/boot/init.c > CMakeFiles/boot.dir/init.c.i

openrtos/boot/CMakeFiles/boot.dir/init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/boot.dir/init.c.s"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/openrtos/boot && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/ite_sdk/openrtos/boot/init.c -o CMakeFiles/boot.dir/init.c.s

openrtos/boot/CMakeFiles/boot.dir/fa626/sync.c.obj: openrtos/boot/CMakeFiles/boot.dir/flags.make
openrtos/boot/CMakeFiles/boot.dir/fa626/sync.c.obj: ../../../openrtos/boot/fa626/sync.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object openrtos/boot/CMakeFiles/boot.dir/fa626/sync.c.obj"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/openrtos/boot && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/boot.dir/fa626/sync.c.obj   -c C:/ite_sdk/openrtos/boot/fa626/sync.c

openrtos/boot/CMakeFiles/boot.dir/fa626/sync.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/boot.dir/fa626/sync.c.i"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/openrtos/boot && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/ite_sdk/openrtos/boot/fa626/sync.c > CMakeFiles/boot.dir/fa626/sync.c.i

openrtos/boot/CMakeFiles/boot.dir/fa626/sync.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/boot.dir/fa626/sync.c.s"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/openrtos/boot && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/ite_sdk/openrtos/boot/fa626/sync.c -o CMakeFiles/boot.dir/fa626/sync.c.s

# Object files for target boot
boot_OBJECTS = \
"CMakeFiles/boot.dir/init.c.obj" \
"CMakeFiles/boot.dir/fa626/sync.c.obj"

# External object files for target boot
boot_EXTERNAL_OBJECTS =

lib/fa626/libboot.a: openrtos/boot/CMakeFiles/boot.dir/init.c.obj
lib/fa626/libboot.a: openrtos/boot/CMakeFiles/boot.dir/fa626/sync.c.obj
lib/fa626/libboot.a: openrtos/boot/CMakeFiles/boot.dir/build.make
lib/fa626/libboot.a: openrtos/boot/CMakeFiles/boot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library ../../lib/fa626/libboot.a"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/openrtos/boot && $(CMAKE_COMMAND) -P CMakeFiles/boot.dir/cmake_clean_target.cmake
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/openrtos/boot && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/boot.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
openrtos/boot/CMakeFiles/boot.dir/build: lib/fa626/libboot.a

.PHONY : openrtos/boot/CMakeFiles/boot.dir/build

openrtos/boot/CMakeFiles/boot.dir/clean:
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/openrtos/boot && $(CMAKE_COMMAND) -P CMakeFiles/boot.dir/cmake_clean.cmake
.PHONY : openrtos/boot/CMakeFiles/boot.dir/clean

openrtos/boot/CMakeFiles/boot.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/ite_sdk C:/ite_sdk/openrtos/boot C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/openrtos/boot C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/openrtos/boot/CMakeFiles/boot.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : openrtos/boot/CMakeFiles/boot.dir/depend

