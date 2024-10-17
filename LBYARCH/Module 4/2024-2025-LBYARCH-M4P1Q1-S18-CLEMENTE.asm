%include "io64.inc"

section .text
var dq 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8
global main
main:
    ;write your code here
    
    MOV al, [var]
    PRINT_HEX 1, al
    
    NEWLINE
    
    MOV al, [var + 8]
    PRINT_HEX 1, al
    
    NEWLINE
    
    MOV al, [var + 16]
    PRINT_HEX 1, al
    
    NEWLINE
    
    MOV al, [var + 24]
    PRINT_HEX 1, al
    
    NEWLINE
    
    MOV al, [var + 32]
    PRINT_HEX 1, al
    
    NEWLINE
    
    MOV al, [var + 40]
    PRINT_HEX 1, al
    
    NEWLINE
    
    MOV al, [var + 48]
    PRINT_HEX 1, al
    
    NEWLINE
    
    MOV al, [var + 56]
    PRINT_HEX 1, al
    
    xor rax, rax
    ret