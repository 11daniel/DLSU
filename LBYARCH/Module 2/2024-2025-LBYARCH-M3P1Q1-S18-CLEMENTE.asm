%include "io64.inc"
section .text
global main
main:
    ;write your code here
    
    GET_DEC 8, RAX
    GET_DEC 8, RBX
    
    add RAX, RBX
    
    PRINT_DEC 8, RAX
    
    xor rax, rax
    ret