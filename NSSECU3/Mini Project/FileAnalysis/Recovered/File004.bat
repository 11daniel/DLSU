@echo off
set /a line=%random% %% 5 + 1
for /f "tokens=*" %%a in (sentences.txt) do (
    set /a count+=1
    if !count! equ %line% echo %%a
)
