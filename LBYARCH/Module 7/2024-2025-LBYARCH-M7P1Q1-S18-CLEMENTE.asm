;Daniel Gavrie Y. Clemente

%include "io64.inc"

section .data
MOTOR dw 0001000100010001b         
section .text
global main
main:
    ;write your code here
    GET_DEC 8, rcx
    
    L1:
        call printmotor
        rol word [MOTOR], 1
        loop L1
             
    xor rax, rax
    ret
    
printmotor:
    PRINT_HEX 2, [MOTOR]
    NEWLINE
    ret