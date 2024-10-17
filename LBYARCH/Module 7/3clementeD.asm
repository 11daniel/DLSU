;Daniel Gavrie Y. Clemente S18
%include "io64.inc"
section .data
count dq 0

section .text
global main
main:
    ;write your code here
    GET_HEX 8, rcx
    mov rax, 0
    
    loop1:
        inc rax
        SHL qword rcx, 1
        jc done
        loop loop1
        
    done:
        mov [count], rax
        
    PRINT_DEC 8, [count]
    xor rax, rax
    ret