@echo off
set message=Loading random text...
for /l %%i in (0,1,20) do (
    set /p "=." <nul
    ping -n 1 127.0.0.1 >nul
)
echo.
echo %message%

