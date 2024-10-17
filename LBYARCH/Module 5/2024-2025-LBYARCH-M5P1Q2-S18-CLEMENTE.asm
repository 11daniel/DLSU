;Daniel Gavrie Clemente
%include "io64.inc"
section .data
var1 dq 0x3333333333333333
var2 dq 0x5555555555555555
var3 dq 0x2222222222222222

section .text
global main
main:
    ;write your code here
    push qword [var1]
    push qword [var2]
    push qword [var3]
    call MOR
    PRINT_HEX 8, rax
    
    xor rax, rax
    ret

MOR:
    MOV RAX, [rsp + 24]
    OR RAX, [rsp + 16]
    OR RAX, [rsp + 8]
    ret 24
    