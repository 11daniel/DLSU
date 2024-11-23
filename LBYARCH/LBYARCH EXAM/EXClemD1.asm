; Clemente, Daniel Gavrie Y. S18
%include "io64.inc"
section .data
    input_string times 200 dd 0
section .text
global main
main:
    mov rbp, rsp; for correct debugging
 
    GET_STRING input_string, 200
    
    mov rsi, input_string
    mov rdi, 1      
    mov rbx, 1
    L1:
        mov al, byte[rsi]
        cmp al, 0x00
        je exit_prog
        
        cmp al, 0x20
        je flags
        
        cmp rdi, 1
        je capitalize
        
        break:
        PRINT_CHAR al
        dec rbx
        dec rdi
        inc rsi
        jmp L1
    
    flags:
        PRINT_CHAR al
        mov rdi, 1
        inc rsi
        jmp L1
         
    capitalize:
        cmp al, 0x61
        jl break
        sub al, 0x20 
        PRINT_CHAR al
        dec rdi
        inc rsi
        jmp L1
        
    exit_prog:
    
    xor rax, rax
    ret
