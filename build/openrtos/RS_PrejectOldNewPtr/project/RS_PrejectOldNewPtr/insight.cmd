@echo off

pushd ..\..\..
call common.cmd
popd

arm-none-eabi-insight -x C:/ite_sdk/sdk/target/debug/fa626/init-gdb RS_PrejectOldNewPtr
if errorlevel 1 pause
