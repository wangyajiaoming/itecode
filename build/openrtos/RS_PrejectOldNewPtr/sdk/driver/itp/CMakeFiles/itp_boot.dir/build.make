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
include sdk/driver/itp/CMakeFiles/itp_boot.dir/depend.make

# Include the progress variables for this target.
include sdk/driver/itp/CMakeFiles/itp_boot.dir/progress.make

# Include the compile flags for this target's objects.
include sdk/driver/itp/CMakeFiles/itp_boot.dir/flags.make

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backtrace.c.obj: sdk/driver/itp/CMakeFiles/itp_boot.dir/flags.make
sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backtrace.c.obj: ../../../sdk/driver/itp/itp_backtrace.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backtrace.c.obj"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/itp_boot.dir/itp_backtrace.c.obj   -c C:/ite_sdk/sdk/driver/itp/itp_backtrace.c

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backtrace.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/itp_boot.dir/itp_backtrace.c.i"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/ite_sdk/sdk/driver/itp/itp_backtrace.c > CMakeFiles/itp_boot.dir/itp_backtrace.c.i

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backtrace.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/itp_boot.dir/itp_backtrace.c.s"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/ite_sdk/sdk/driver/itp/itp_backtrace.c -o CMakeFiles/itp_boot.dir/itp_backtrace.c.s

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_base.c.obj: sdk/driver/itp/CMakeFiles/itp_boot.dir/flags.make
sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_base.c.obj: ../../../sdk/driver/itp/itp_base.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_base.c.obj"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/itp_boot.dir/itp_base.c.obj   -c C:/ite_sdk/sdk/driver/itp/itp_base.c

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_base.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/itp_boot.dir/itp_base.c.i"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/ite_sdk/sdk/driver/itp/itp_base.c > CMakeFiles/itp_boot.dir/itp_base.c.i

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_base.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/itp_boot.dir/itp_base.c.s"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/ite_sdk/sdk/driver/itp/itp_base.c -o CMakeFiles/itp_boot.dir/itp_base.c.s

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_defer.c.obj: sdk/driver/itp/CMakeFiles/itp_boot.dir/flags.make
sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_defer.c.obj: ../../../sdk/driver/itp/itp_defer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_defer.c.obj"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/itp_boot.dir/itp_defer.c.obj   -c C:/ite_sdk/sdk/driver/itp/itp_defer.c

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_defer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/itp_boot.dir/itp_defer.c.i"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/ite_sdk/sdk/driver/itp/itp_defer.c > CMakeFiles/itp_boot.dir/itp_defer.c.i

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_defer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/itp_boot.dir/itp_defer.c.s"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/ite_sdk/sdk/driver/itp/itp_defer.c -o CMakeFiles/itp_boot.dir/itp_defer.c.s

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_error.c.obj: sdk/driver/itp/CMakeFiles/itp_boot.dir/flags.make
sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_error.c.obj: ../../../sdk/driver/itp/itp_error.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_error.c.obj"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/itp_boot.dir/itp_error.c.obj   -c C:/ite_sdk/sdk/driver/itp/itp_error.c

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_error.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/itp_boot.dir/itp_error.c.i"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/ite_sdk/sdk/driver/itp/itp_error.c > CMakeFiles/itp_boot.dir/itp_error.c.i

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_error.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/itp_boot.dir/itp_error.c.s"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/ite_sdk/sdk/driver/itp/itp_error.c -o CMakeFiles/itp_boot.dir/itp_error.c.s

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_vmem.c.obj: sdk/driver/itp/CMakeFiles/itp_boot.dir/flags.make
sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_vmem.c.obj: ../../../sdk/driver/itp/itp_vmem.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_vmem.c.obj"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/itp_boot.dir/itp_vmem.c.obj   -c C:/ite_sdk/sdk/driver/itp/itp_vmem.c

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_vmem.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/itp_boot.dir/itp_vmem.c.i"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/ite_sdk/sdk/driver/itp/itp_vmem.c > CMakeFiles/itp_boot.dir/itp_vmem.c.i

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_vmem.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/itp_boot.dir/itp_vmem.c.s"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/ite_sdk/sdk/driver/itp/itp_vmem.c -o CMakeFiles/itp_boot.dir/itp_vmem.c.s

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_lcdconsole.c.obj: sdk/driver/itp/CMakeFiles/itp_boot.dir/flags.make
sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_lcdconsole.c.obj: ../../../sdk/driver/itp/itp_lcdconsole.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_lcdconsole.c.obj"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/itp_boot.dir/itp_lcdconsole.c.obj   -c C:/ite_sdk/sdk/driver/itp/itp_lcdconsole.c

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_lcdconsole.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/itp_boot.dir/itp_lcdconsole.c.i"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/ite_sdk/sdk/driver/itp/itp_lcdconsole.c > CMakeFiles/itp_boot.dir/itp_lcdconsole.c.i

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_lcdconsole.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/itp_boot.dir/itp_lcdconsole.c.s"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/ite_sdk/sdk/driver/itp/itp_lcdconsole.c -o CMakeFiles/itp_boot.dir/itp_lcdconsole.c.s

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_screen.c.obj: sdk/driver/itp/CMakeFiles/itp_boot.dir/flags.make
sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_screen.c.obj: ../../../sdk/driver/itp/itp_screen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_screen.c.obj"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/itp_boot.dir/itp_screen.c.obj   -c C:/ite_sdk/sdk/driver/itp/itp_screen.c

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_screen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/itp_boot.dir/itp_screen.c.i"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/ite_sdk/sdk/driver/itp/itp_screen.c > CMakeFiles/itp_boot.dir/itp_screen.c.i

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_screen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/itp_boot.dir/itp_screen.c.s"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/ite_sdk/sdk/driver/itp/itp_screen.c -o CMakeFiles/itp_boot.dir/itp_screen.c.s

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backlight.c.obj: sdk/driver/itp/CMakeFiles/itp_boot.dir/flags.make
sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backlight.c.obj: ../../../sdk/driver/itp/itp_backlight.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backlight.c.obj"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/itp_boot.dir/itp_backlight.c.obj   -c C:/ite_sdk/sdk/driver/itp/itp_backlight.c

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backlight.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/itp_boot.dir/itp_backlight.c.i"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/ite_sdk/sdk/driver/itp/itp_backlight.c > CMakeFiles/itp_boot.dir/itp_backlight.c.i

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backlight.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/itp_boot.dir/itp_backlight.c.s"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/ite_sdk/sdk/driver/itp/itp_backlight.c -o CMakeFiles/itp_boot.dir/itp_backlight.c.s

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_uart.c.obj: sdk/driver/itp/CMakeFiles/itp_boot.dir/flags.make
sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_uart.c.obj: ../../../sdk/driver/itp/itp_uart.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_uart.c.obj"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/itp_boot.dir/itp_uart.c.obj   -c C:/ite_sdk/sdk/driver/itp/itp_uart.c

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_uart.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/itp_boot.dir/itp_uart.c.i"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/ite_sdk/sdk/driver/itp/itp_uart.c > CMakeFiles/itp_boot.dir/itp_uart.c.i

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_uart.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/itp_boot.dir/itp_uart.c.s"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/ite_sdk/sdk/driver/itp/itp_uart.c -o CMakeFiles/itp_boot.dir/itp_uart.c.s

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.obj: sdk/driver/itp/CMakeFiles/itp_boot.dir/flags.make
sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.obj: ../../../sdk/driver/itp/itp_posix_openrtos.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.obj"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.obj   -c C:/ite_sdk/sdk/driver/itp/itp_posix_openrtos.c

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.i"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/ite_sdk/sdk/driver/itp/itp_posix_openrtos.c > CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.i

sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.s"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && C:/ITEGCC/bin/arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/ite_sdk/sdk/driver/itp/itp_posix_openrtos.c -o CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.s

# Object files for target itp_boot
itp_boot_OBJECTS = \
"CMakeFiles/itp_boot.dir/itp_backtrace.c.obj" \
"CMakeFiles/itp_boot.dir/itp_base.c.obj" \
"CMakeFiles/itp_boot.dir/itp_defer.c.obj" \
"CMakeFiles/itp_boot.dir/itp_error.c.obj" \
"CMakeFiles/itp_boot.dir/itp_vmem.c.obj" \
"CMakeFiles/itp_boot.dir/itp_lcdconsole.c.obj" \
"CMakeFiles/itp_boot.dir/itp_screen.c.obj" \
"CMakeFiles/itp_boot.dir/itp_backlight.c.obj" \
"CMakeFiles/itp_boot.dir/itp_uart.c.obj" \
"CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.obj"

# External object files for target itp_boot
itp_boot_EXTERNAL_OBJECTS =

lib/fa626/libitp_boot.a: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backtrace.c.obj
lib/fa626/libitp_boot.a: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_base.c.obj
lib/fa626/libitp_boot.a: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_defer.c.obj
lib/fa626/libitp_boot.a: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_error.c.obj
lib/fa626/libitp_boot.a: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_vmem.c.obj
lib/fa626/libitp_boot.a: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_lcdconsole.c.obj
lib/fa626/libitp_boot.a: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_screen.c.obj
lib/fa626/libitp_boot.a: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_backlight.c.obj
lib/fa626/libitp_boot.a: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_uart.c.obj
lib/fa626/libitp_boot.a: sdk/driver/itp/CMakeFiles/itp_boot.dir/itp_posix_openrtos.c.obj
lib/fa626/libitp_boot.a: sdk/driver/itp/CMakeFiles/itp_boot.dir/build.make
lib/fa626/libitp_boot.a: sdk/driver/itp/CMakeFiles/itp_boot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C static library ../../../lib/fa626/libitp_boot.a"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && $(CMAKE_COMMAND) -P CMakeFiles/itp_boot.dir/cmake_clean_target.cmake
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/itp_boot.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sdk/driver/itp/CMakeFiles/itp_boot.dir/build: lib/fa626/libitp_boot.a

.PHONY : sdk/driver/itp/CMakeFiles/itp_boot.dir/build

sdk/driver/itp/CMakeFiles/itp_boot.dir/clean:
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp && $(CMAKE_COMMAND) -P CMakeFiles/itp_boot.dir/cmake_clean.cmake
.PHONY : sdk/driver/itp/CMakeFiles/itp_boot.dir/clean

sdk/driver/itp/CMakeFiles/itp_boot.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/ite_sdk C:/ite_sdk/sdk/driver/itp C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/driver/itp/CMakeFiles/itp_boot.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sdk/driver/itp/CMakeFiles/itp_boot.dir/depend

