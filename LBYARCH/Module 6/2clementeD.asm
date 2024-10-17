%include "io64.inc"
section .data
length dq 0
width dq 0
perimeter dq 0
area dq 0
section .text
global main
main:
    ;write your code here
    
    xor rax, rax
    xor rbx, rbx
    
    GET_DEC 8, length
    GET_DEC 8, width
    
    mov rax, [length]
    mov rbx, [width]
    
    add [perimeter], rax
    add [perimeter], rbx
    add [perimeter], rax
    add [perimeter], rbx
   
    mov rcx, rbx
    imul rcx
    mov [area], rax
    
    
    PRINT_STRING "Perimeter: "
    PRINT_DEC 8, [perimeter]
    NEWLINE
    PRINT_STRING "Area: "
    PRINT_DEC 8, [area]
    NEWLINE
    
    xor rax, rax
    xor rbx, rbx
    ret