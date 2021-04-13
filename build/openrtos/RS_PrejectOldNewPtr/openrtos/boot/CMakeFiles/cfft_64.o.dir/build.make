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

# Utility rule file for cfft_64.o.

# Include the progress variables for this target.
include openrtos/boot/CMakeFiles/cfft_64.o.dir/progress.make

openrtos/boot/CMakeFiles/cfft_64.o: lib/fa626/cfft_64.o


lib/fa626/cfft_64.o: ../../../openrtos/boot/fa626/cfft_64.s
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating ../../lib/fa626/cfft_64.o"
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/openrtos/boot && C:/ITEGCC/bin/arm-none-eabi-gcc.exe -DCFG_CHIP_REV_A0 -DCFG_CHIP_PKG_IT976 -DCFG_OSC_CLK=12000000 -DCFG_RTC_EXTCLK=32768 -DCFG_AXI_DMA -DCFG_CHIP_FAMILY=970 -DCFG_RAM_SIZE=0x4000000 -DCFG_MEMDBG_ENABLE -DCFG_DCPS_ENABLE -DCFG_CPU_WB -DCFG_WT_SIZE=0x200000 -DCFG_MMAP_SIZE=0 -DCFG_LCD_ENABLE -DCFG_LCD_WIDTH=720 -DCFG_LCD_HEIGHT=1280 -DCFG_LCD_PITCH=1440 -DCFG_LCD_BPP=2 -DCFG_LCD_TRIPLE_BUFFER -DCFG_BACKLIGHT_ENABLE -DCFG_BACKLIGHT_FREQ=1000 "-DCFG_BACKLIGHT_DUTY_CYCLES=95, 92, 88, 82, 75, 65, 55, 40, 25, 5" -DCFG_BACKLIGHT_DEFAULT_DUTY_CYCLE=65 -DCFG_BACKLIGHT_BOOTLODER_DELAY=200 -DCFG_BL_SHOW_LOGO -DCFG_LCD_BOOT_BGCOLOR=0x000000 -DCFG_CMDQ_ENABLE -DCFG_CMDQ_SIZE=0x40000 -DCFG_M2D_ENABLE -DCFG_JPEG_HW_ENABLE -DCFG_FONT_FILENAME="wqyMicroHeiProportional.ttf" -DCFG_AUDIO_ENABLE -DAUDIO_PLUGIN_MESSAGE_QUEUE -DENABLE_CODECS_PLUGIN -DCONFIG_ITADRIVER -DCFG_RISC_ENABLE -DCFG_AUDIO_SAMPLING_RATE=8000 -DCFG_AEC_DELAY_MS=60 -DCFG_SPEAKER_GAIN=0 -DCFG_MIC_GAIN=0 -DCFG_NOISE_GATE_THRESHOLD=0.3 -DCFG_EQUALIZER_SPKGAIN_SET=NULL -DCFG_EQUALIZER_MICGAIN_SET=NULL -DCFG_AUDIO_CODEC_MP3DEC -DCFG_AUDIO_CODEC_WAV -DCFG_AUDIO_CODEC_WMADEC -DCFG_AUDIO_MGR_THREAD_STACK_SIZE=64 -DCFG_AUDIO_MGR_READ_BUFFER_SIZE=64 -DCFG_AUDIO_SPECIAL_CASE_BUFFER_SIZE=64 -DCFG_STC_ENABLE -DCFG_VIDEO_ENABLE -DCFG_VIDEO_MAX_WIDTH=1920 -DCFG_VIDEO_MAX_HEIGHT=1088 -DCFG_VIDEO_BUFFER_PITCH=2048 -DCFG_VIDEO_DECODE_MODE=1 -DTWO_WAY_AUDIORECORD -DCFG_BUILD_ITV -DCFG_BUILD_ITU -DCFG_ITU_FT_CACHE_ENABLE -DCFG_NOR_ENABLE -DCFG_NOR_RESERVED_SIZE=0x250000 -DCFG_NOR_CACHE_SIZE=0x200000 -DCFG_NOR_CACHE_FLUSH_INTERVAL=0 -DCFG_NOR_USE_AXISPI -DCFG_NOR_ENABLE_QUADMODE -DCFG_MSC_ENABLE -DCFG_FS_FAT -DCFG_PRIVATE_DRIVE="A" -DCFG_PUBLIC_DRIVE="B" -DCFG_TEMP_DRIVE="C" -DCFG_BACKUP_DRIVE="D" -DCFG_CHECK_FILES_CRC_ON_BOOTING -DCFG_NOR_PARTITION3 -DCFG_RTC_ENABLE -DCFG_RTC_DEFAULT_TIMESTAMP=1325376000 -DCFG_INTERNAL_RTC_TIMER=4 -DCFG_I2C2_ENABLE -DCFG_AXISPI_ENABLE -DCFG_AXISPI_MOSI_GPIO=7 -DCFG_AXISPI_MISO_GPIO=8 -DCFG_AXISPI_CLOCK_GPIO=5 -DCFG_AXISPI_CHIP_SEL_GPIO=6 -DCFG_AXISPI_WP_GPIO=9 -DCFG_AXISPI_HOLD_GPIO=10 -DCFG_I2S_ENABLE -DENABLE_I2S_INTERNAL_CODEC -DCFG_AXISPI_ENABLE -DCFG_BUILD_I2S -DCFG_UART0_ENABLE -DCFG_UART0_BAUDRATE=115200 -DCFG_UART0_INTR -DCFG_UART_INTR_BUF_SIZE=16384 -DCFG_UART1_ENABLE -DCFG_UART1_BAUDRATE=19200 -DCFG_UART1_INTR -DCFG_UART_INTR_BUF_SIZE=16384 -DCFG_USB0_ENABLE -DCFG_USB1_ENABLE -DCFG_TOUCH_ENABLE -DCFG_TOUCH_MODULE_COUNT=1 -DCFG_TOUCH_I2C2 -DCFG_TOUCH_CAPACITIVE -DCFG_TOUCH_INTR -DCFG_TOUCH_X_MAX_VALUE=0x2CF -DCFG_TOUCH_Y_MAX_VALUE=0x4FF -DCFG_AMPLIFIER_ENABLE -DCFG_POWER_STANDBY -DCFG_POWER_STANDBY_CPU_FREQ_RATIO=15 -DCFG_POWER_STANDBY_BUS_FREQ_RATIO=30 -DCFG_POWER_DOZE "-DCFG_GPIO_SD0_IO=16, 17, 18, 19, 20, 21, -1, -1, -1, -1" -DCFG_GPIO_BACKLIGHT_PWM=39 -DCFG_GPIO_PWM_NUMBER=6 -DCFG_GPIO_PWM_MODE=4 -DCFG_GPIO_UART0_TX=4 -DCFG_GPIO_UART0_RX=-1 -DCFG_GPIO_UART1_TX=37 -DCFG_GPIO_UART1_RX=36 -DCFG_GPIO_IIC1_CLK=37 -DCFG_GPIO_IIC1_DATA=36 -DCFG_GPIO_IIC1_MODE=2 -DCFG_GPIO_IIC2_CLK=45 -DCFG_GPIO_IIC2_DATA=46 -DCFG_GPIO_TOUCH_INT=47 -DCFG_GPIO_TOUCH_WAKE=-1 -DCFG_GPIO_TOUCH_RESET=44 -DCFG_GPIO_AMPLIFIER_ENABLE=24 -DCFG_GPIO_AMPLIFIER_MUTE=24 -DCFG_GPIO_ETHERNET_LINK=-1 -DCFG_NET_ETHERNET_PHY_ADDR=-1 -DCFG_NET_ETHERNET_COUNT=1 -DCFG_TASK_DRIVE_PROBE -DCFG_DBG_PRINTBUF_SIZE=0 -DCFG_DBG_UART0 -DCFG_DBG_STATS -DCFG_DBG_STATS_PERIOD=10 -DCFG_DBG_STATS_HEAP -DCFG_UPGRADE_FILENAME="ITEPKG03.PKG" -DCFG_UPGRADE_FILENAME_LIST="ITEPKG03.PKG" -DCFG_UPGRADE_ENC_KEY=0 -DCFG_UPGRADE_OPEN_FILE -DCFG_UPGRADE_IMAGE_NOR -DCFG_UPGRADE_IMAGE_POS=0x80000 -DCFG_UPGRADE_DELETE_PKGFILE_AFTER_FINISH -DCFG_UPGRADE_DELAY_AFTER_FINISH=10 -DCFG_UPGRADE_USB_DETECT_TIMEOUT=600 -DCFG_UPGRADE_USB_TIMEOUT=8000 -DCFG_UPGRADE_MARK_POS=0 -DCFG_COMPRESS_AUDIO_PLUGIN -DCFG_BUILD_AUDIO_MGR -DCFG_NORMAL_BUFFER_MODE -DCFG_ENABLE_ROTATE -DCFG_BUILD_MINSIZEREL -DCFG_VERSION_MAJOR=2 -DCFG_VERSION_MINOR=3 -DCFG_VERSION_PATCH=3 -DCFG_VERSION_CUSTOM=2 -DCFG_VERSION_TWEAK= -DCFG_VERSION_MAJOR_STR="2" -DCFG_VERSION_MINOR_STR="3" -DCFG_VERSION_PATCH_STR="3" -DCFG_VERSION_CUSTOM_STR="2" -DCFG_VERSION_TWEAK_STR="" -DCFG_SYSTEM_NAME="ITE Display Control Board" -DCFG_MANUFACTURER="www.ite.com.tw" -DCFG_PROJECT_NAME="RS_PrejectOldNewPtr" -D__DYNAMIC_REENT__ -D__OPENRTOS__=1 -D_DEFAULT_SOURCE -D_GNU_SOURCE -D_POSIX_BARRIERS -D_POSIX_C_SOURCE=200809L -D_POSIX_MONOTONIC_CLOCK -D_POSIX_PRIORITY_SCHEDULING=1 -D_POSIX_READER_WRITER_LOCKS -D_POSIX_THREADS -D_POSIX_TIMERS -D_UNIX98_THREAD_MUTEX_ATTRIBUTES -DOSIP_MT -DCFG_GCC_LTO -DMALLOC_ALIGNMENT=32 -DCFG_OPENRTOS_HEAP_SIZE=0 -DCFG_LCDC_HEIGHT=1280 -DCFG_LCDC_PITCH=1440 -c -o C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/lib/fa626/cfft_64.o C:/ite_sdk/openrtos/boot/fa626/cfft_64.s

cfft_64.o: openrtos/boot/CMakeFiles/cfft_64.o
cfft_64.o: lib/fa626/cfft_64.o
cfft_64.o: openrtos/boot/CMakeFiles/cfft_64.o.dir/build.make

.PHONY : cfft_64.o

# Rule to build all files generated by this target.
openrtos/boot/CMakeFiles/cfft_64.o.dir/build: cfft_64.o

.PHONY : openrtos/boot/CMakeFiles/cfft_64.o.dir/build

openrtos/boot/CMakeFiles/cfft_64.o.dir/clean:
	cd C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/openrtos/boot && $(CMAKE_COMMAND) -P CMakeFiles/cfft_64.o.dir/cmake_clean.cmake
.PHONY : openrtos/boot/CMakeFiles/cfft_64.o.dir/clean

openrtos/boot/CMakeFiles/cfft_64.o.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/ite_sdk C:/ite_sdk/openrtos/boot C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/openrtos/boot C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/openrtos/boot/CMakeFiles/cfft_64.o.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : openrtos/boot/CMakeFiles/cfft_64.o.dir/depend

