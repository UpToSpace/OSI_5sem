@echo off
echo --params: %*
echo --rejim: %1
echo --filename: %2

if "%*" equ "" goto help
if "%2" equ "" echo filename is empty & goto exit

if /i "%1" equ "create" goto create
if /i "%1" equ "delete" goto delete
if /i "%1" neq "delete" goto errorRejim else if /i "%1" neq "create" goto errorRejim

:help
echo z03-06 rejim, file
echo rejim = {create, delete}
echo file = filename
goto exit

:errorRejim
echo rejim is not correct
goto exit

:create
if not exist %2 (copy nul %2 & echo the file was created) else (echo file already exists)
goto exit

:delete
if not exist %2 (echo file is not exists) else (del %2 & echo the file was deleted)
goto exit

:exit
pause