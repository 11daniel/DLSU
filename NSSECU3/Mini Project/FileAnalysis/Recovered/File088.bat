@echo off
for /l %%i in (1,1,32) do (
    set /a r=%random% %% 16
    set /p=%%r <nul
)
echo.
