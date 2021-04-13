@echo off

cd %CMAKE_SOURCE_DIR%\build\%CFG_PLATFORM%\%CFG_PROJECT%\project\%TARGET%

glamomem -t glamomem.dat -i -q
glamomem -t glamomem.dat -l bootloader.bin

if "970" == "970" (
    glamomem -t glamomem.dat -R 0x00000001 -a 0xd8300000
) else (
    if "970" == "960" (
        glamomem -t glamomem.dat -R 0x00000001 -a 0xd8300000
    ) else (
        glamomem -t glamomem.dat -R 0x0025 -a 0x1F00
    )
)
