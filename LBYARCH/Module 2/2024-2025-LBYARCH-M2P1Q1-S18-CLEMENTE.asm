; Clemente, Daniel Gavrie S18

%include "io64.inc"

section .data
    
section .text

global main

main:

    mov RAX, 0X1
    
    PRINT_DEC 8, RAX
    
    NEWLINE
    
    add RAX, RAX
    
    PRINT_DEC 8, RAX
    
    NEWLINE
    
    add RAX, RAX
    
    PRINT_DEC 8, RAX
    
    NEWLINE
    
    add RAX, RAX
    
    PRINT_DEC 8, RAX
    
    NEWLINE
    
    add RAX, RAX
    
    PRINT_DEC 8, RAX
    
    NEWLINE
    
    add RAX, RAX
    
    PRINT_DEC 8, RAX
    
    NEWLINE
    
    add RAX, RAX
    
    PRINT_DEC 8, RAX
    
    NEWLINE
    
    add RAX, RAX
    
    PRINT_DEC 8, RAX
    
    NEWLINE
    
    add RAX, RAX
    
    PRINT_DEC 8, RAX
    
    NEWLINE
    
    add RAX, RAX
    
    PRINT_DEC 8, RAX
    
    NEWLINE
    
    add RAX, RAX
    
    PRINT_DEC 8, RAX
    
    NEWLINE
    
    xor rax, rax
    
    ret
