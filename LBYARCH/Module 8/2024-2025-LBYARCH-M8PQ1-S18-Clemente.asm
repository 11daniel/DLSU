; CLEMENTE, Daniel Gavrie Y. S18

%include "io64.inc"
section .data
A dq 4.0
B dq 2.0
numSqrt dq 0.0

X1 dq 0.0
X2 dq 0.0
X3 dq 0.0
X4 dq 0.0
X5 dq 0.0
X6 dq 0.0

section .text
global main
main:
    mov rbp, rsp; for correct debugging
    
    movsd xmm1, [A]
    movsd xmm2, [B]
    
    movsd xmm3, [numSqrt]
    
    movsd xmm4, [X1]
    movsd xmm5, [X2]
    movsd xmm6, [X3]
    movsd xmm7, [X4]
    movsd xmm8, [X5]
    movsd xmm9, [X6]

    ; SUM:
    movsd xmm1, [A]
    movsd xmm2, [B]
    addsd xmm1, xmm2
    movsd xmm4, xmm1
    
    ; SUB:
    movsd xmm1, [A]
    movsd xmm2, [B]
    subsd xmm1, xmm2
    movsd xmm5, xmm1
        
    ; PRODUCT:
    movsd xmm1, [A]
    movsd xmm2, [B]
    mulsd xmm1, xmm2
    movsd xmm6, xmm1
    
    ; DIV
    movsd xmm1, [A]
    movsd xmm2, [B]
    divsd xmm1, xmm2
    movsd xmm7, xmm1
    
    ; RECRIPOCAL
    movsd xmm1, [A]
    movsd xmm2, [B]
    divsd xmm2, xmm1
    movsd xmm8, xmm2
    
    ; SQRT
    movsd xmm1, [A]
    movsd xmm2, [B]
    sqrtsd xmm4, xmm1
    movsd xmm9, xmm4
    
    ; convert to integer
    cvtsd2si eax, xmm4
    cvtsd2si ebx, xmm5
    cvtsd2si ecx, xmm6
    cvtsd2si edx, xmm7
    cvtsd2si r8d, xmm8
    cvtsd2si r9d, xmm9
    
    
    ; PRINT VALUES
    
    PRINT_STRING "OUTPUT VALUES"
    NEWLINE
    PRINT_STRING "SUM: "
    PRINT_DEC 8, eax
    NEWLINE 
    PRINT_STRING "SUB: "
    PRINT_DEC 8, ebx
    NEWLINE
    PRINT_STRING "PRODUCT: "
    PRINT_DEC 8, ecx
    NEWLINE
    PRINT_STRING "QUOTIENT: "
    PRINT_DEC 8, edx
    NEWLINE
    PRINT_STRING "RECIPROCAL: "
    PRINT_DEC 8, r8d
    NEWLINE      
    PRINT_STRING "SQRT: "
    PRINT_DEC 8, r9d
    NEWLINE                
    
       
    xor rax, rax
    ret