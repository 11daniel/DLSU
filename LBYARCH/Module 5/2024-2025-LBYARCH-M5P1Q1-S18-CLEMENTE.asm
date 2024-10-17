%include "io64.inc"

section .text
global main
main:
    ;write your code here
    GET_DEC 8, RAX
    GET_DEC 8, RBX
    
    CMP RAX, RBX
    JG else
        PRINT_STRING "less than or equal"
    JMP endif
    else:
        PRINT_STRING "greater than"
    endif:;next instruction
    xor rax, rax
    ret