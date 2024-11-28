nasm -f win64 MP2.asm
gcc -c MP2_C.c -o MP2_C.obj -m64
gcc MP2_C.obj MP2.obj -o MP2_C.exe -m64
MP2_C.exe < 5.txt 
pause