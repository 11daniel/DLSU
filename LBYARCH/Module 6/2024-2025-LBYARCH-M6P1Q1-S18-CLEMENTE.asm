%include "io64.inc"
section .data
var1 dq 0
var2 dq 0
varsum dq 0
vardiff dq 0
varprod dq 0
varqot dq 0
varrem dq 0
section .text
global main
main:
    ;write your code here
    mov rbp, rsp
    GET_DEC 8, var1
    GET_DEC 8, var2
    
    mov rax, [var1]
    mov rbx, [var2]
    
    add [varsum], rax
    add [varsum], rbx
    
    mov [vardiff], rax
    sub [vardiff], rbx
    
    mov rcx, rbx
    imul rcx
    mov [varprod], rax
    
    mov rax, [var1]
    xor rdx, rdx
    idiv rbx
    mov [varqot], rax
    mov [varrem], rbx
    
    PRINT_STRING "Sum: "
    PRINT_DEC 8, [varsum]
    NEWLINE
    PRINT_STRING "Difference: "
    PRINT_DEC 8, [vardiff]
    NEWLINE
    PRINT_STRING "Product: "
    PRINT_DEC 8, [varprod]
    NEWLINE
    PRINT_STRING "Quotient: "
    PRINT_DEC 8, [varqot]
    NEWLINE
    PRINT_STRING "Remainder: "
    PRINT_DEC 8, [varrem]
    
    xor rax, rax
    ret