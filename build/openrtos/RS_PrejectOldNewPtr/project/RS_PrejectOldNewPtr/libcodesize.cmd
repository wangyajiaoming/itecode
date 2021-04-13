@echo off

pushd ..\..\..
call common.cmd
popd

C:/ite_sdk/tool/bin/libCodeSize C:/ITEGCC/BIN/arm-none-eabi-readelf.exe C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/lib/fa626 C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/project/RS_PrejectOldNewPtr/RS_PrejectOldNewPtr.symbol RS_PrejectOldNewPtr_CodeSize.txt

pause
