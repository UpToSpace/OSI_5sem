@echo off
echo --params: %*
echo --param 1: %1
echo --param 2: %2
echo --param 3: %3
set /a x = %1 + %2
echo --%1 + %2 = %x%
set /a x = %1 * %2
echo --%1 * %2 = %x%
set /a x = %3 / %2
echo --%3 / %2 = %x%
set /a x = %2 - %1
echo --%2 - %1 = %x%
set /a x = (%2 - %1)*(%1 - %2)
echo --(%2 - %1)*(%1 - %2) = %x%
pause