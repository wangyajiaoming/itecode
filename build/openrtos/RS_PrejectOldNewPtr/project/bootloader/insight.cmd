@echo off

pushd ..\..\..
call common.cmd
popd

arm-none-eabi-insight -x C:/ite_sdk/sdk/target/debug/fa626/init-gdb bootloader
if errorlevel 1 pause
