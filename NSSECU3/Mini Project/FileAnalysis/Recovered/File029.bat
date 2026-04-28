@echo off
for /f "tokens=1-4 delims=/ " %%a in ("%date%") do set day=%%a
if %day% equ Mon echo Today feels lucky!
if %day% equ Tue echo Keep moving forward.
if %day% equ Wed echo Happy hump day!
if %day% equ Thu echo Almost there.
if %day% equ Fri echo It's Friday!
