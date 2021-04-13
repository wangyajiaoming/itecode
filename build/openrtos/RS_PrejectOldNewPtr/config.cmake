#
# Automatically generated file; DO NOT EDIT.
# Project Configuration
# Tue Mar 16 09:13:34 2021
#
#
set(CFG_CTRLBOARD y)
set(CFG_DEF_CHIP_PKG_IT976 y)
set(CFG_DEF_CHIP_REV_A0 y)
set(CFG_RAM_SIZE "0x4000000")
set(CFG_RAM_INIT_SCRIPT "IT970A0_396Mhz_DDR2_396Mhz.scr")
set(CFG_TILING_WIDTH_128 0)
set(CFG_WATCHDOG_ENABLE y)
set(CFG_DCPS_ENABLE y)
set(CFG_FONT_FILENAME "wqyMicroHeiProportional.ttf")
set(CFG_BACKLIGHT_ENABLE y)
set(CFG_BACKLIGHT_DUTY_CYCLES "95, 92, 88, 82, 75, 65, 55, 40, 25, 5")
set(CFG_BACKLIGHT_DEFAULT_DUTY_CYCLE "65")
set(CFG_LCD_ENABLE y)

#
# (unvisible)
#
set(CFG_LCD_WIDTH "720")
set(CFG_LCD_HEIGHT "1280")
set(CFG_LCD_PITCH "1440")
set(CFG_LCD_INIT_SCRIPT "it970_lcd_guanxian_1280x720_18bits_rgb_new2021_128pin.txt")
set(CFG_CMDQ_ENABLE y)
set(CFG_M2D_ENABLE y)
set(CFG_JPEG_HW_ENABLE y)
set(CFG_AUDIO_ENABLE y)
set(CFG_AUDIO_DAC_MODULE "itp_dac_ite970.c")
set(CFG_AUDIO_CODEC_MP3DEC y)
set(CFG_AUDIO_CODEC_WMADEC y)
set(CFG_AUDIO_CODEC_WAV y)
set(CFG_COMPRESS_AUDIO_PLUGIN y)
set(CFG_VIDEO_ENABLE y)
set(CFG_NOR_ENABLE y)
set(CFG_NOR_USE_AXISPI y)
set(CFG_NOR_ENABLE_QUADMODE y)

#
# (unvisible)
#
set(CFG_NOR_CACHE_SIZE "0x200000")
set(CFG_NOR_RESERVED_SIZE "0x250000")
set(CFG_NOR_PARTITION0 y)
set(CFG_NOR_PARTITION0_SIZE "0xAF0000")
set(CFG_NOR_PARTITION1 y)
set(CFG_NOR_PARTITION1_SIZE "0x260000")
set(CFG_NOR_PARTITION2 y)
set(CFG_NOR_PARTITION2_SIZE "0x40000")
set(CFG_NOR_PARTITION3 y)
# CFG_SD0_ENABLE is not set
set(CFG_GPIO_SD0_IO "16, 17, 18, 19, 20, 21, -1, -1, -1, -1")

#
# (unvisible)
#

#
# (unvisible)
#
set(CFG_USB0_ENABLE y)
set(CFG_USB1_ENABLE y)
set(CFG_MSC_ENABLE y)
set(CFG_FS_FAT y)
set(CFG_RTC_ENABLE y)
# CFG_SPI_ENABLE is not set
# CFG_I2C1_ENABLE is not set
set(CFG_GPIO_IIC1_CLK "37")
set(CFG_GPIO_IIC1_DATA "36")
set(CFG_GPIO_IIC1_MODE "2")
set(CFG_TOUCH_ENABLE y)
set(CFG_TOUCH_MODULE "gt911")
set(CFG_TOUCH_X_MAX_VALUE "0x2CF")
set(CFG_TOUCH_Y_MAX_VALUE "0x4FF")
set(CFG_GPIO_TOUCH_INT "47")
set(CFG_GPIO_TOUCH_RESET "44")
set(CFG_GPIO_TOUCH_WAKE "-1")
set(CFG_DEF_TOUCH_I2C1 y)
set(CFG_TOUCH_INTR y)
set(CFG_I2S_ENABLE y)
# CFG_I2S_SPDIF_ENABLE is not set
set(CFG_POWER_SAVING_ENABLE y)
set(CFG_DEF_POWER_STANDBY y)
set(CFG_POWER_STANDBY_CPU_FREQ_RATIO "15")
set(CFG_POWER_STANDBY_BUS_FREQ_RATIO "30")
set(CFG_UART0_ENABLE y)
set(CFG_GPIO_UART0_TX "4")
set(CFG_GPIO_UART0_RX "-1")
set(CFG_AXISPI_ENABLE y)
set(CFG_AXISPI_MOSI_GPIO "7")
set(CFG_AXISPI_MISO_GPIO "8")
set(CFG_AXISPI_CLOCK_GPIO "5")
set(CFG_AXISPI_CHIP_SEL_GPIO "6")
set(CFG_AXISPI_WP_GPIO "9")
set(CFG_AXISPI_HOLD_GPIO "10")
set(CFG_GPIO_BACKLIGHT_PWM "39")
# CFG_GPIO_EXPANDER_ENABLE is not set
# CFG_NET_ENABLE is not set
set(CFG_TASK_DRIVE_PROBE y)
set(CFG_DEF_DBG_UART0 y)
set(CFG_DBG_INIT_SCRIPT "IT970A0_396Mhz_DDR2_396Mhz.txt")
set(CFG_DBG_STATS y)
set(CFG_DBG_STATS_HEAP y)
set(CFG_DEF_BUILD_MINSIZEREL y)
set(CFG_SYSTEM_NAME "ITE Display Control Board")
set(CFG_ITU_FT_CACHE_ENABLE y)
set(CFG_ITU_FT_CACHE_SIZE "0xFA000")
set(CFG_GCC_LTO y)
set(CFG_BUILD_AUDIO_MGR y)
set(CFG_BUILD_INIPARSER y)
set(CFG_BUILD_ITU y)
set(CFG_BUILD_SDL y)
set(CFG_BUILD_UPGRADE y)
set(CFG_BUILD_PYINPUT y)

#
# (unvisible)
#

#
# (unvisible)
#
set(CFG_BOOTLOADER_ENABLE y)

#
# (unvisible)
#
set(CFG_LCD_BOOT_BITMAP "rishun5inch_logo.png")
set(CFG_BL_SHOW_LOGO y)

#
# (unvisible)
#
set(CFG_UPGRADE_BOOTLOADER y)
set(CFG_UPGRADE_IMAGE y)
set(CFG_UPGRADE_DATA y)

#
# (unvisible)
#
set(CFG_UPGRADE_PRIVATE y)
set(CFG_UPGRADE_PUBLIC y)
set(CFG_UPGRADE_TEMP y)
set(CFG_UPGRADE_OPEN_FILE y)
set(CFG_UPGRADE_PARTITION y)
set(CFG_UPGRADE_DELETE_PKGFILE_AFTER_FINISH y)

#
# (unvisible)
#
set(CFG_DEF_UPGRADE_BOOTLOADER_NOR y)
set(CFG_DEF_UPGRADE_IMAGE_NOR y)
set(CFG_UPGRADE_IMAGE_POS "0x80000")
set(CFG_DEF_UPGRADE_PRIVATE_NOR y)
set(CFG_DEF_UPGRADE_PUBLIC_NOR y)
set(CFG_DEF_UPGRADE_TEMP_NOR y)
set(CFG_UPGRADE_NOR_IMAGE y)
set(CFG_UPGRADE_NOR_IMAGE_SIZE "0x1000000")
set(CFG_BL_LCD_CONSOLE y)
set(CFG_BL_ERR y)
set(CFG_BL_WARN y)
set(CFG_BL_INFO y)
set(CFG_BL_DBG y)
set(CFG_CHECK_FILES_CRC_ON_BOOTING y)
set(CFG_HAVE_LCD y)
set(CFG_HAVE_GRAPHICS y)
set(CFG_HAVE_AUDIO y)
set(CFG_HAVE_VIDEO y)

#
# (unvisible)
#
set(CFG_DEF_CFG_RELEASE y)

#
# (unvisible)
#

#
# Develop Environment
#
set(CFG_DEV_DEVELOP y)
# CFG_DEV_RELEASE is not set

#
# OpenRTOS
#
set(CFG_OPENRTOS_HEAP_SIZE "0")
# CFG_OPENRTOS_USE_TRACE_FACILITY is not set
# CFG_OPENRTOS_GENERATE_RUN_TIME_STATS is not set
# CFG_OPENRTOS_CLI is not set

#
# System
#
set(CFG_CPU_FA626 y)
# CFG_CPU_SM32 is not set
set(CFG_CHIP_REV_A0 y)
# CFG_CHIP_REV_A1 is not set
# CFG_CHIP_REV_B0 is not set
set(CFG_CHIP_FAMILY_IT970 y)
# CFG_CHIP_PKG_IT978 is not set
# CFG_CHIP_PKG_IT977 is not set
set(CFG_CHIP_PKG_IT976 y)
# CFG_CHIP_PKG_IT972 is not set
# CFG_CHIP_PKG_IT960 is not set
set(CFG_MMAP_SIZE "0")
set(CFG_WATCHDOG_TIMEOUT 10)
set(CFG_WATCHDOG_REFRESH_INTERVAL 1)
# CFG_WATCHDOG_INTR is not set
# CFG_WATCHDOG_IDLETASK is not set
# CFG_EXT_WATCHDOG_ENABLE is not set

#
# Internal Settings
#
set(CFG_MEMDBG_ENABLE y)
set(CFG_ROM_COMPRESS y)
# CFG_DPU_ENABLE is not set
# CFG_SPREAD_SPECTRUM_PLL1_ENABLE is not set
# CFG_SPREAD_SPECTRUM_PLL2_ENABLE is not set
# CFG_SPREAD_SPECTRUM_PLL3_ENABLE is not set
set(CFG_CPU_WB y)
# CFG_XCPU_MSGQ is not set

#
# Screen
#
set(CFG_ENABLE_ROTATE y)
set(CFG_LCD_BPP "2")
# CFG_LCD_MULTIPLE is not set
set(CFG_LCD_TRIPLE_BUFFER y)
# CFG_HDMI_OUT_ENABLE is not set
set(CFG_LCD_BOOT_BGCOLOR "0x000000")
# CFG_LCD_BOOT_BITMAP_DITHER is not set
set(CFG_BACKLIGHT_FREQ "1000")
set(CFG_BACKLIGHT_BOOTLODER_DELAY "200")

#
# Internal Setting
#
# CFG_TVOUT_ENABLE is not set

#
# Graphics
#
set(CFG_CMDQ_SIZE "0x40000")
# CFG_M2D_MEMPOOL_ENABLE is not set

#
# Audio
#
# CFG_RISC_TS_DEMUX_PLUGIN is not set
# CFG_DIALOGUE_PARAMETER_SET is not set

#
# Speech Filter (unvisible)
#

#
# Speech Coding Codec (unvisible)
#

#
# Music Codec
#
# CFG_AUDIO_CODEC_AACDEC is not set
# CFG_AUDIO_CODEC_MP2ENC is not set
# CFG_AUDIO_MGR_RESAMPLE is not set
# CFG_AUDIO_MGR_PARSING_MP3 is not set

#
# Audio Mgr Buffer Size Setting
#
set(CFG_AUDIO_MGR_THREAD_STACK_SIZE "64")
set(CFG_AUDIO_MGR_READ_BUFFER_SIZE "64")
set(CFG_AUDIO_SPECIAL_CASE_BUFFER_SIZE "64")

#
# Video
#
# CFG_MPEGENCODER_ENABLE is not set
# CFG_TS_MODULE_ENABLE is not set
# CFG_UVC_ENABLE is not set
# CFG_MJPEG_DEC_ENABLE is not set

#
# Storage
#
# CFG_NAND_ENABLE is not set
set(CFG_NOR_CACHE_FLUSH_INTERVAL "0")
# CFG_NOR_ENABLE_DTRMODE is not set
# CFG_SD1_ENABLE is not set
# CFG_RAMDISK_ENABLE is not set
# CFG_UAS_ENABLE is not set

#
# File System
#
set(CFG_NOR_PARTITION3_SIZE "0")
set(CFG_PRIVATE_DRIVE "A")
set(CFG_PUBLIC_DRIVE "B")
set(CFG_TEMP_DRIVE "C")
set(CFG_BACKUP_DRIVE "D")

#
# Peripheral
#
set(CFG_RTC_MODULE "itp_rtc_internal.c")
# CFG_RTC_USE_I2C is not set
# CFG_RTC_REDUCE_IO_ACCESS_ENABLE is not set
set(CFG_RTC_DEFAULT_TIMESTAMP "1325376000")
set(CFG_INTERNAL_RTC_TIMER "4")
# CFG_I2C0_ENABLE is not set
set(CFG_I2C2_ENABLE y)
# CFG_I2C3_ENABLE is not set
set(CFG_I2S_INTERNAL_CODEC y)
# CFG_RGBTOMIPI_ENABLE is not set
# CFG_WIEGAND_ENABLE is not set
# CFG_TV_ENCODER_ENABLE is not set
# CFG_IOEX_ENABLE is not set
set(CFG_UART0_INTR y)
# CFG_UART0_DMA is not set
# CFG_UART0_FIFO is not set
set(CFG_UART0_BAUDRATE "115200")
set(CFG_UART1_ENABLE y)
set(CFG_UART1_INTR y)
# CFG_UART1_DMA is not set
# CFG_UART1_FIFO is not set
set(CFG_UART1_BAUDRATE "19200")
# CFG_UART2_ENABLE is not set
# CFG_UART3_ENABLE is not set
# CFG_UART4_ENABLE is not set
# CFG_UART5_ENABLE is not set
set(CFG_UART_INTR_BUF_SIZE "16384")
# CFG_UART_FORCE_FLUSH is not set
# CFG_RS485_0_ENABLE is not set
# CFG_RS485_1_ENABLE is not set
# CFG_RS485_2_ENABLE is not set
# CFG_RS485_3_ENABLE is not set
# CFG_RS485_4_ENABLE is not set
# CFG_RS485_5_ENABLE is not set
# CFG_SWUART_CODEC_ENABLE is not set
# CFG_USB_DEVICE is not set
# CFG_IRDA_ENABLE is not set
# CFG_IR0_ENABLE is not set
# CFG_KEYPAD_ENABLE is not set
set(CFG_TOUCH_I2C2 y)
set(CFG_TOUCH_CAPACITIVE y)
# CFG_TOUCH_RESISTIVE is not set
# CFG_TOUCH_MULTI_FINGER is not set
# CFG_TOUCH_BUTTON is not set
# CFG_TOUCH_ADVANCE_CONFIG is not set
# CFG_BATTERY_ENABLE is not set
# CFG_GSENSOR_ENABLE is not set
# CFG_HEADSET_ENABLE is not set
# CFG_SPEAKER_ENABLE is not set
set(CFG_AMPLIFIER_ENABLE y)
set(CFG_AMPLIFIER_MODULE "itp_amp_gpio.c")
# CFG_LED_ENABLE is not set
# CFG_TUNER_ENABLE is not set
set(CFG_CAPTURE_DEFINE "DEMO_976_DoorCamera_NT99141.txt")
# CFG_SENSOR_ENABLE is not set
# CFG_HDMI_RX_ENABLE is not set
# CFG_HDMI_TX_ENABLE is not set
# CFG_USB_HID_ENABLE is not set
# CFG_USB_SERIAL is not set
# CFG_ALT_CPU_ENABLE is not set
# CFG_SARADC_ENABLE is not set
# CFG_CANBUS_ENABLE is not set
# CFG_CANBUS1_ENABLE is not set

#
# Power
#
set(CFG_POWER_STANDBY y)
# CFG_POWER_SLEEP is not set
set(CFG_POWER_DOZE y)
# CFG_POWER_TICKLESS_IDLE is not set

#
# GPIO
#
set(CFG_GPIO_PWM_NUMBER "6")
set(CFG_GPIO_PWM_MODE "4")
set(CFG_GPIO_UART1_TX "37")
set(CFG_GPIO_UART1_RX "36")
# CFG_GPIO_TOUCH_INT_ACTIVE_HIGH is not set
set(CFG_GPIO_AMPLIFIER_ENABLE "24")
set(CFG_GPIO_AMPLIFIER_MUTE "24")
set(CFG_GPIO_IIC2_CLK "45")
set(CFG_GPIO_IIC2_DATA "46")

#
# Network
#

#
# (unvisible)
#
# CFG_USB_ECM is not set

#
# Task
#

#
# Debug
#
# CFG_DBG_NONE is not set
# CFG_DBG_PRINTBUF is not set
# CFG_DBG_SWUART_CODEC is not set
set(CFG_DBG_UART0 y)
# CFG_DBG_UART1 is not set
# CFG_DBG_LCDCONSOLE is not set
# CFG_DBG_OSDCONSOLE is not set
set(CFG_DBG_ICE_SCRIPT "IT9070A1_Initial_DDR2_Mem_tiling_pitch2048_320MHZ.csf")
# CFG_DBG_BLUESCREEN is not set
# CFG_DBG_MEMLEAK is not set
set(CFG_DBG_STATS_PERIOD "10")
# CFG_DBG_STATS_MEM_BANDWIDTH is not set
# CFG_DBG_STATS_GPIO is not set
# CFG_DBG_STATS_FAT is not set
# CFG_ENABLE_UART_CLI is not set
# CFG_BOOT_TESTBIN_ENABLE is not set
# CFG_DBG_OUTPUT_DEBUG_FILES is not set

#
# Upgrade
#
# CFG_UPGRADE_BOOTLOADER_NAND is not set
set(CFG_UPGRADE_BOOTLOADER_NOR y)
# CFG_UPGRADE_BOOTLOADER_SD0 is not set
# CFG_UPGRADE_BOOTLOADER_SD1 is not set
# CFG_UPGRADE_BOOTLOADER_EXTERNAL_PROJECT is not set
# CFG_UPGRADE_IMAGE_NAND is not set
set(CFG_UPGRADE_IMAGE_NOR y)
# CFG_UPGRADE_IMAGE_SD0 is not set
# CFG_UPGRADE_IMAGE_SD1 is not set
# CFG_UPGRADE_PRIVATE_NAND is not set
set(CFG_UPGRADE_PRIVATE_NOR y)
# CFG_UPGRADE_PRIVATE_SD0 is not set
# CFG_UPGRADE_PRIVATE_SD1 is not set
# CFG_UPGRADE_PUBLIC_NAND is not set
set(CFG_UPGRADE_PUBLIC_NOR y)
# CFG_UPGRADE_PUBLIC_SD0 is not set
# CFG_UPGRADE_PUBLIC_SD1 is not set
# CFG_UPGRADE_TEMP_NAND is not set
set(CFG_UPGRADE_TEMP_NOR y)
# CFG_UPGRADE_TEMP_SD0 is not set
# CFG_UPGRADE_TEMP_SD1 is not set
set(CFG_UPGRADE_ENC_KEY "0")
# CFG_UPGRADE_PRESSKEY is not set
set(CFG_UPGRADE_FILENAME "ITEPKG03.PKG")
set(CFG_UPGRADE_FILENAME_LIST "ITEPKG03.PKG")
set(CFG_UPGRADE_DELAY_AFTER_FINISH "10")
set(CFG_UPGRADE_USB_DETECT_TIMEOUT "600")
set(CFG_UPGRADE_USB_TIMEOUT "8000")
set(CFG_UPGRADE_NOR_IMAGE_FILENAME "ITE_NOR.ROM")
set(CFG_UPGRADE_PACKAGE_VERSION "1.0")
# CFG_UPGRADE_BACKUP_PACKAGE is not set
set(CFG_UPGRADE_MARK_POS "0")

#
# SDK
#
# CFG_BUILD_DEBUG is not set
# CFG_BUILD_DEBUGREL is not set
# CFG_BUILD_RELEASE is not set
set(CFG_BUILD_MINSIZEREL y)
set(CFG_VERSION_MAJOR "2")
set(CFG_VERSION_MINOR "3")
set(CFG_VERSION_PATCH "3")
set(CFG_VERSION_CUSTOM "2")
set(CFG_MANUFACTURER "www.ite.com.tw")
# CFG_GENERATE_DOC is not set
# CFG_GENERATE_PACK_ENV is not set
# CFG_GENERATE_VERSION_TWEAK is not set

#
# Drivers
#

#
# ith
#
set(CFG_ITH_ERR y)
set(CFG_ITH_WARN y)
set(CFG_ITH_INFO y)
# CFG_ITH_DBG is not set
# CFG_ITH_FPGA is not set

#
# itp
#
set(CFG_ITP_ERR y)
set(CFG_ITP_WARN y)
set(CFG_ITP_INFO y)
# CFG_ITP_DBG is not set

#
# Libraries
#

#
# (unvisible)
#

#
# cli (unvisible)
#

#
# (unvisible)
#

#
# (unvisible)
#

#
# dhcps (unvisible)
#
set(CFG_BUILD_ITC y)
set(CFG_BUILD_ZLIB y)

#
# ffmpeg
#
# CFG_FFMPEG_ENC is not set
# CFG_FFMPEG_H264_SW is not set

#
# (unvisible)
#

#
# itc
#
set(CFG_ITC_ERR y)
set(CFG_ITC_WARN y)
set(CFG_ITC_INFO y)
# CFG_ITC_DBG is not set

#
# (unvisible)
#

#
# itu
#
set(CFG_ITU_ERR y)
set(CFG_ITU_WARN y)
set(CFG_ITU_INFO y)
# CFG_ITU_DBG is not set
# CFG_ITU_LOAD is not set
# CFG_ITU_UPDATE is not set
# CFG_ITU_DRAW is not set
# CFG_ITU_UCL_ENABLE is not set
set(CFG_ITU_ASSERT_THREAD y)
set(CFG_BUILD_FFMPEG y)
set(CFG_BUILD_FREETYPE y)
set(CFG_BUILD_ITU_RENDERER y)
set(CFG_BUILD_PNG y)
set(CFG_BUILD_REDBLACK y)

#
# (unvisible)
#

#
# sdl
#
# CFG_SDL_M2D_ENABLE is not set

#
# (unvisible)
#

#
# tslib
#
# CFG_TSLIB_STATIC_CONF is not set

#
# (unvisible)
#

#
# upgrade
#
set(CFG_UG_ERR y)
set(CFG_UG_WARN y)
set(CFG_UG_INFO y)
# CFG_UG_DBG is not set
set(CFG_UG_BUF_SIZE "0x20000")

#
# Display Control Board
#
set(CFG_HW_VERSION "V03")
# CFG_SCREENSHOT_ENABLE is not set
set(CFG_WEBSERVER_PORT "80")
set(CFG_ITU_PATH "itu/1280x720")
set(CFG_UPGRADE_FTP_URL "ftp://192.168.1.1/ctrlboard/ITEPKG03.PKG")
# CFG_UPGRADE_GUI is not set
# CFG_DYNAMIC_LOAD_TP_MODULE is not set
