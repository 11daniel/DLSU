@echo off
set word=hello
set scrambled=
for /l %%i in (0,1,%strlen%) do (
    set /a idx=%random% %% 5
    set scrambled=!scrambled!!word:~%idx%,1!
)
echo Scrambled Word: %scrambled%
