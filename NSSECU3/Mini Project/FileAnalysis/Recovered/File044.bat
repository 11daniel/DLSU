@echo off
setlocal enabledelayedexpansion
set words=apple banana cherry dragonfruit elderberry
set /a idx=%random% %% 5
for /l %%i in (0,1,%idx%) do (
    for %%w in (%words%) do set chosen=%%w
)
echo Random Word: !chosen!