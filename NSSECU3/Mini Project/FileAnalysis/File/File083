@echo off
set /a num=%random% %% 26 + 65
for /f %%a in ('cmd /c exit %num%') do set "char=%%a"
echo Random Letter: %char%