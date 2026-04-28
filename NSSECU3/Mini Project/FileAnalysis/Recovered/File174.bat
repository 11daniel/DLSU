@echo off
set /a a=%random% %% 100
set /a b=%random% %% 100
set /a result=%a%+%b%
echo %a% + %b% = %result%
