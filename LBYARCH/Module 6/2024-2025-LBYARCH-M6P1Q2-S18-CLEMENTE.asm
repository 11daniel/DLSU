%include "io64.inc"
section .data
N dq 0
dset times 100 dq 0
sum dq 0
mean dq 0
sumsqdiff dq 0
variance dq 0

section .text
global main
main:

    ;write your code here   
    
    ; N
    GET_DEC 8, [N]
    ; inputs
    mov rcx, [N]
    mov rbx, 0
    L1:
        GET_DEC 8, [dset+rbx]
        add rbx, 8
        dec rcx
        cmp rcx, 0
        jnz L1
    
    ; sum
    mov rcx, [N]
    mov rbx, 0
    L2:
        mov rax, [dset+rbx]
        add [sum], rax
        add rbx, 8
        dec rcx
        cmp rcx, 0
        jnz L2
    
    PRINT_STRING "Sum: "
    PRINT_DEC 8, [sum]
    NEWLINE
    
    ; mean
    mov rax, [sum]
    mov rcx, [N]
    xor rdx, rdx
    div rcx
    mov [mean], rax
    
    PRINT_STRING "Mean: "
    PRINT_DEC 8, [mean]
    NEWLINE
    
    ; sum of sq diff
    mov rcx, [N]
    mov rbx, 0
    xor rax, rax
    L3:
        mov rax, [dset+rbx]
        sub rax, [mean]
        imul rax, rax
        add [sumsqdiff], rax
        add rbx, 8
        dec rcx
        cmp rcx, 0
        jnz L3
    
    ; variance
    mov rax, [sumsqdiff]
    mov rcx, [N]
    dec rcx
    xor rdx, rdx
    div rcx
    mov [variance], rax
    
    PRINT_STRING "Variance: "
    PRINT_DEC 8, [variance]
    NEWLINE
    
    xor rax, rax
    ret