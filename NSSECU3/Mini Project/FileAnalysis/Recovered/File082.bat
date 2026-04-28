@echo off
set paths=C:\Windows\ C:\Users\ C:\Program Files\
set /a idx=%random% %% 3
for %%p in (%paths%) do (
    if !idx! equ 0 echo %%p
)
