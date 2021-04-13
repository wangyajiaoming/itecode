@echo off

pushd ..\..\..
call common.cmd
popd

rem glamomem -t glamomem.dat -i -q
rem glamomem -t glamomem.dat -l bootloader.bin

if "970" == "970" (
    glamomem -t glamomem.dat -q -e C:/ite_sdk/sdk/target/debug/fa626/JTAG_Switch_32bits.txt
) else (
    if "970" == "960" (
        glamomem -t glamomem.dat -q -e C:/ite_sdk/sdk/target/debug/fa626/JTAG_Switch_32bits.txt
    ) else (
        glamomem -t glamomem.dat -q -e C:/ite_sdk/sdk/target/debug/fa626/JTAG_Switch_16bits.txt
    )
)

openocd -f C:/ite_sdk/sdk/target/debug/fa626/fa626.cfg
