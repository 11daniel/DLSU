@echo off
set /a count=%random% %% 20 + 1
echo Generating:
for /l %%i in (1,1,%count%) do (
    set /p "=#" <nul
    ping -n 1 127.0.0.1 >nul
)
echo. Done!
