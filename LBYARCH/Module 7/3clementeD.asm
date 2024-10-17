;Daniel Gavrie Y. Clemente S18
%include "io64.inc"
section .data
count dq 0

section .text
global main
main:
    ;write your code here
    GET_HEX 8, rax
    xor rbx, rbx
    
    loop1:
        rol qword rax, 1
        jc done
        inc rbx
        jnc loop1
        
    done:
        mov [count], rax
        PRINT_DEC 8, [count]

    xor rax, rax
    ret
