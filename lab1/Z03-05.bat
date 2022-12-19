@echo off
echo --params: %*
echo --param 1: %1
echo --param 2: %2
echo --param 3: %3
set /a x = %1 %3 %2
echo --result: %x%
pause