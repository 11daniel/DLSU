%include "io64.inc"

section .text
var15 dd 0xA1, 0xB1, 0xC1, 0xA2, 0xB2, 0xC2, 0xA3, 0xB3, 0xC3
global main
main:
    ;write your code here
    
    MOV EAX, [var15]
    PRINT_HEX 4, EAX
    
    MOV EAX, [var15 + 12]
    PRINT_HEX 4, EAX
    
    MOV EAX, [var15 + 24]
    PRINT_HEX 4, EAX
    
    NEWLINE
    
    MOV EAX, [var15 + 4]
    PRINT_HEX 4, EAX
    
    MOV EAX, [var15 + 16]
    PRINT_HEX 4, EAX
    
    MOV EAX, [var15 + 28] 
    PRINT_HEX 4, EAX
    
    NEWLINE
    
    MOV EAX, [var15 + 8]
    PRINT_HEX 4, EAX
    
    MOV EAX, [var15 + 20]
    PRINT_HEX 4, EAX
    
    MOV EAX, [var15 + 32]
    PRINT_HEX 4, EAX
    
    xor rax, rax
    ret