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
include sdk/driver/msc/CMakeFiles/msc.dir/depend.make

# Include the progress variables for this target.
include sdk/driver/msc/CMakeFiles/msc.dir/progress.make

# Include the compile flags for this target's objects.
include sdk/driver/msc/CMakeFiles/msc.dir/flags.make

sdk/driver/msc/CMakeFiles/msc.dir/usb.c.obj: sdk/driver/msc/CMakeFiles/msc.dir/flags.make
sdk/driver/msc/CMakeFiles/msc.dir/usb.c.obj: ../../../sdk/driver/msc/usb.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object sdk/driver/msc/CMakeFiles/msc.dir/usb.c.obj"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/msc && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/msc.dir/usb.c.obj   -c C:/ite_sdk/sdk/driver/msc/usb.c

sdk/driver/msc/CMakeFiles/msc.dir/usb.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/msc.dir/usb.c.i"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/msc && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/ite_sdk/sdk/driver/msc/usb.c > CMakeFiles/msc.dir/usb.c.i

sdk/driver/msc/CMakeFiles/msc.dir/usb.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/msc.dir/usb.c.s"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/msc && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/ite_sdk/sdk/driver/msc/usb.c -o CMakeFiles/msc.dir/usb.c.s

sdk/driver/msc/CMakeFiles/msc.dir/transport.c.obj: sdk/driver/msc/CMakeFiles/msc.dir/flags.make
sdk/driver/msc/CMakeFiles/msc.dir/transport.c.obj: ../../../sdk/driver/msc/transport.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object sdk/driver/msc/CMakeFiles/msc.dir/transport.c.obj"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/msc && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/msc.dir/transport.c.obj   -c C:/ite_sdk/sdk/driver/msc/transport.c

sdk/driver/msc/CMakeFiles/msc.dir/transport.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/msc.dir/transport.c.i"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/msc && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/ite_sdk/sdk/driver/msc/transport.c > CMakeFiles/msc.dir/transport.c.i

sdk/driver/msc/CMakeFiles/msc.dir/transport.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/msc.dir/transport.c.s"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/msc && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/ite_sdk/sdk/driver/msc/transport.c -o CMakeFiles/msc.dir/transport.c.s

sdk/driver/msc/CMakeFiles/msc.dir/scsi.c.obj: sdk/driver/msc/CMakeFiles/msc.dir/flags.make
sdk/driver/msc/CMakeFiles/msc.dir/scsi.c.obj: ../../../sdk/driver/msc/scsi.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object sdk/driver/msc/CMakeFiles/msc.dir/scsi.c.obj"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/msc && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/msc.dir/scsi.c.obj   -c C:/ite_sdk/sdk/driver/msc/scsi.c

sdk/driver/msc/CMakeFiles/msc.dir/scsi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/msc.dir/scsi.c.i"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/msc && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/ite_sdk/sdk/driver/msc/scsi.c > CMakeFiles/msc.dir/scsi.c.i

sdk/driver/msc/CMakeFiles/msc.dir/scsi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/msc.dir/scsi.c.s"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/msc && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/ite_sdk/sdk/driver/msc/scsi.c -o CMakeFiles/msc.dir/scsi.c.s

sdk/driver/msc/CMakeFiles/msc.dir/mmp_msc.c.obj: sdk/driver/msc/CMakeFiles/msc.dir/flags.make
sdk/driver/msc/CMakeFiles/msc.dir/mmp_msc.c.obj: ../../../sdk/driver/msc/mmp_msc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object sdk/driver/msc/CMakeFiles/msc.dir/mmp_msc.c.obj"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/msc && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/msc.dir/mmp_msc.c.obj   -c C:/ite_sdk/sdk/driver/msc/mmp_msc.c

sdk/driver/msc/CMakeFiles/msc.dir/mmp_msc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/msc.dir/mmp_msc.c.i"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/msc && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/ite_sdk/sdk/driver/msc/mmp_msc.c > CMakeFiles/msc.dir/mmp_msc.c.i

sdk/driver/msc/CMakeFiles/msc.dir/mmp_msc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/msc.dir/mmp_msc.c.s"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/msc && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/ite_sdk/sdk/driver/msc/mmp_msc.c -o CMakeFiles/msc.dir/mmp_msc.c.s

# Object files for target msc
msc_OBJECTS = \
"CMakeFiles/msc.dir/usb.c.obj" \
"CMakeFiles/msc.dir/transport.c.obj" \
"CMakeFiles/msc.dir/scsi.c.obj" \
"CMakeFiles/msc.dir/mmp_msc.c.obj"

# External object files for target msc
msc_EXTERNAL_OBJECTS =

lib/fa626/libmsc.a: sdk/driver/msc/CMakeFiles/msc.dir/usb.c.obj
lib/fa626/libmsc.a: sdk/driver/msc/CMakeFiles/msc.dir/transport.c.obj
lib/fa626/libmsc.a: sdk/driver/msc/CMakeFiles/msc.dir/scsi.c.obj
lib/fa626/libmsc.a: sdk/driver/msc/CMakeFiles/msc.dir/mmp_msc.c.obj
lib/fa626/libmsc.a: sdk/driver/msc/CMakeFiles/msc.dir/build.make
lib/fa626/libmsc.a: sdk/driver/msc/CMakeFiles/msc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C static library ../../../lib/fa626/libmsc.a"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/msc && $(CMAKE_COMMAND) -P CMakeFiles/msc.dir/cmake_clean_target.cmake
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/msc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/msc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sdk/driver/msc/CMakeFiles/msc.dir/build: lib/fa626/libmsc.a

.PHONY : sdk/driver/msc/CMakeFiles/msc.dir/build

sdk/driver/msc/CMakeFiles/msc.dir/clean:
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/msc && $(CMAKE_COMMAND) -P CMakeFiles/msc.dir/cmake_clean.cmake
.PHONY : sdk/driver/msc/CMakeFiles/msc.dir/clean

sdk/driver/msc/CMakeFiles/msc.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/ite_sdk C:/ite_sdk/sdk/driver/msc C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/msc C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/msc/CMakeFiles/msc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sdk/driver/msc/CMakeFiles/msc.dir/depend
