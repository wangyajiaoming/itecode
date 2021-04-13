# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# compile C with C:/ITEGCC/bin/arm-none-eabi-gcc.exe
C_FLAGS = -flto=4 -ffat-lto-objects -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -fsigned-char -Wno-unused-result -mcpu=fa626te -fno-short-enums -Wl,--no-enum-size-warning -Os -g3 -DNDEBUG   

C_DEFINES = -DAUDIO_PLUGIN_MESSAGE_QUEUE -DCFG_AEC_DELAY_MS=60 -DCFG_AMPLIFIER_ENABLE -DCFG_AUDIO_CODEC_MP3DEC -DCFG_AUDIO_CODEC_WAV -DCFG_AUDIO_CODEC_WMADEC -DCFG_AUDIO_ENABLE -DCFG_AUDIO_MGR_READ_BUFFER_SIZE=64 -DCFG_AUDIO_MGR_THREAD_STACK_SIZE=64 -DCFG_AUDIO_SAMPLING_RATE=8000 -DCFG_AUDIO_SPECIAL_CASE_BUFFER_SIZE=64 -DCFG_AXISPI_CHIP_SEL_GPIO=6 -DCFG_AXISPI_CLOCK_GPIO=5 -DCFG_AXISPI_ENABLE -DCFG_AXISPI_HOLD_GPIO=10 -DCFG_AXISPI_MISO_GPIO=8 -DCFG_AXISPI_MOSI_GPIO=7 -DCFG_AXISPI_WP_GPIO=9 -DCFG_AXI_DMA -DCFG_BACKLIGHT_BOOTLODER_DELAY=200 -DCFG_BACKLIGHT_DEFAULT_DUTY_CYCLE=65 -DCFG_BACKLIGHT_DUTY_CYCLES="95, 92, 88, 82, 75, 65, 55, 40, 25, 5" -DCFG_BACKLIGHT_ENABLE -DCFG_BACKLIGHT_FREQ=1000 -DCFG_BACKUP_DRIVE=\"D\" -DCFG_BL_SHOW_LOGO -DCFG_BUILD_AUDIO_MGR -DCFG_BUILD_I2S -DCFG_BUILD_ITU -DCFG_BUILD_ITV -DCFG_BUILD_MINSIZEREL -DCFG_CHECK_FILES_CRC_ON_BOOTING -DCFG_CHIP_FAMILY=970 -DCFG_CHIP_PKG_IT976 -DCFG_CHIP_REV_A0 -DCFG_CMDQ_ENABLE -DCFG_CMDQ_SIZE=0x40000 -DCFG_COMPRESS_AUDIO_PLUGIN -DCFG_CPU_WB -DCFG_DBG_PRINTBUF_SIZE=0 -DCFG_DBG_STATS -DCFG_DBG_STATS_HEAP -DCFG_DBG_STATS_PERIOD=10 -DCFG_DBG_UART0 -DCFG_DCPS_ENABLE -DCFG_ENABLE_ROTATE -DCFG_EQUALIZER_MICGAIN_SET=NULL -DCFG_EQUALIZER_SPKGAIN_SET=NULL -DCFG_FONT_FILENAME=\"wqyMicroHeiProportional.ttf\" -DCFG_FS_FAT -DCFG_GCC_LTO -DCFG_GPIO_AMPLIFIER_ENABLE=24 -DCFG_GPIO_AMPLIFIER_MUTE=24 -DCFG_GPIO_BACKLIGHT_PWM=39 -DCFG_GPIO_ETHERNET_LINK=-1 -DCFG_GPIO_IIC1_CLK=37 -DCFG_GPIO_IIC1_DATA=36 -DCFG_GPIO_IIC1_MODE=2 -DCFG_GPIO_IIC2_CLK=45 -DCFG_GPIO_IIC2_DATA=46 -DCFG_GPIO_PWM_MODE=4 -DCFG_GPIO_PWM_NUMBER=6 -DCFG_GPIO_SD0_IO="16, 17, 18, 19, 20, 21, -1, -1, -1, -1" -DCFG_GPIO_TOUCH_INT=47 -DCFG_GPIO_TOUCH_RESET=44 -DCFG_GPIO_TOUCH_WAKE=-1 -DCFG_GPIO_UART0_RX=-1 -DCFG_GPIO_UART0_TX=4 -DCFG_GPIO_UART1_RX=36 -DCFG_GPIO_UART1_TX=37 -DCFG_I2C2_ENABLE -DCFG_I2S_ENABLE -DCFG_INTERNAL_RTC_TIMER=4 -DCFG_ITU_FT_CACHE_ENABLE -DCFG_JPEG_HW_ENABLE -DCFG_LCD_BOOT_BGCOLOR=0x000000 -DCFG_LCD_BPP=2 -DCFG_LCD_ENABLE -DCFG_LCD_HEIGHT=1280 -DCFG_LCD_PITCH=1440 -DCFG_LCD_TRIPLE_BUFFER -DCFG_LCD_WIDTH=720 -DCFG_M2D_ENABLE -DCFG_MANUFACTURER=\"www.ite.com.tw\" -DCFG_MEMDBG_ENABLE -DCFG_MIC_GAIN=0 -DCFG_MMAP_SIZE=0 -DCFG_MSC_ENABLE -DCFG_NET_ETHERNET_COUNT=1 -DCFG_NET_ETHERNET_PHY_ADDR=-1 -DCFG_NOISE_GATE_THRESHOLD=0.3 -DCFG_NORMAL_BUFFER_MODE -DCFG_NOR_CACHE_FLUSH_INTERVAL=0 -DCFG_NOR_CACHE_SIZE=0x200000 -DCFG_NOR_ENABLE -DCFG_NOR_ENABLE_QUADMODE -DCFG_NOR_PARTITION3 -DCFG_NOR_RESERVED_SIZE=0x250000 -DCFG_NOR_USE_AXISPI -DCFG_OPENRTOS_HEAP_SIZE=0 -DCFG_OSC_CLK=12000000 -DCFG_POWER_DOZE -DCFG_POWER_STANDBY -DCFG_POWER_STANDBY_BUS_FREQ_RATIO=30 -DCFG_POWER_STANDBY_CPU_FREQ_RATIO=15 -DCFG_PRIVATE_DRIVE=\"A\" -DCFG_PROJECT_NAME=\"RS_PrejectOldNewPtr\" -DCFG_PUBLIC_DRIVE=\"B\" -DCFG_RAM_SIZE=0x4000000 -DCFG_RISC_ENABLE -DCFG_RTC_DEFAULT_TIMESTAMP=1325376000 -DCFG_RTC_ENABLE -DCFG_RTC_EXTCLK=32768 -DCFG_SPEAKER_GAIN=0 -DCFG_STC_ENABLE -DCFG_SYSTEM_NAME="\"ITE Display Control Board\"" -DCFG_TASK_DRIVE_PROBE -DCFG_TEMP_DRIVE=\"C\" -DCFG_TOUCH_CAPACITIVE -DCFG_TOUCH_ENABLE -DCFG_TOUCH_I2C2 -DCFG_TOUCH_INTR -DCFG_TOUCH_MODULE_COUNT=1 -DCFG_TOUCH_X_MAX_VALUE=0x2CF -DCFG_TOUCH_Y_MAX_VALUE=0x4FF -DCFG_UART0_BAUDRATE=115200 -DCFG_UART0_ENABLE -DCFG_UART0_INTR -DCFG_UART1_BAUDRATE=19200 -DCFG_UART1_ENABLE -DCFG_UART1_INTR -DCFG_UART_INTR_BUF_SIZE=16384 -DCFG_UPGRADE_DELAY_AFTER_FINISH=10 -DCFG_UPGRADE_DELETE_PKGFILE_AFTER_FINISH -DCFG_UPGRADE_ENC_KEY=0 -DCFG_UPGRADE_FILENAME=\"ITEPKG03.PKG\" -DCFG_UPGRADE_FILENAME_LIST=\"ITEPKG03.PKG\" -DCFG_UPGRADE_IMAGE_NOR -DCFG_UPGRADE_IMAGE_POS=0x80000 -DCFG_UPGRADE_MARK_POS=0 -DCFG_UPGRADE_OPEN_FILE -DCFG_UPGRADE_USB_DETECT_TIMEOUT=600 -DCFG_UPGRADE_USB_TIMEOUT=8000 -DCFG_USB0_ENABLE -DCFG_USB1_ENABLE -DCFG_VERSION_CUSTOM=2 -DCFG_VERSION_CUSTOM_STR=\"2\" -DCFG_VERSION_MAJOR=2 -DCFG_VERSION_MAJOR_STR=\"2\" -DCFG_VERSION_MINOR=3 -DCFG_VERSION_MINOR_STR=\"3\" -DCFG_VERSION_PATCH=3 -DCFG_VERSION_PATCH_STR=\"3\" -DCFG_VERSION_TWEAK="" -DCFG_VERSION_TWEAK_STR=\"\" -DCFG_VIDEO_BUFFER_PITCH=2048 -DCFG_VIDEO_DECODE_MODE=1 -DCFG_VIDEO_ENABLE -DCFG_VIDEO_MAX_HEIGHT=1088 -DCFG_VIDEO_MAX_WIDTH=1920 -DCFG_WT_SIZE=0x200000 -DCONFIG_ITADRIVER -DENABLE_CODECS_PLUGIN -DENABLE_I2S_INTERNAL_CODEC -DMALLOC_ALIGNMENT=32 -DOSIP_MT -DTWO_WAY_AUDIORECORD -D_DEFAULT_SOURCE -D_GNU_SOURCE -D_POSIX_BARRIERS -D_POSIX_C_SOURCE=200809L -D_POSIX_MONOTONIC_CLOCK -D_POSIX_PRIORITY_SCHEDULING=1 -D_POSIX_READER_WRITER_LOCKS -D_POSIX_THREADS -D_POSIX_TIMERS -D_UNIX98_THREAD_MUTEX_ATTRIBUTES -D__DYNAMIC_REENT__ -D__OPENRTOS__=1

C_INCLUDES = -IC:/ite_sdk/openrtos/include -IC:/ite_sdk/sdk/include -IC:/ite_sdk/sdk/driver/itv/. -IC:/ite_sdk/sdk/include/ite -IC:/ite_sdk/sdk/share/ffmpeg 

