; CLEMENTE, Daniel Gavrie Y. S18

%include "io64.inc"
section .data
A dq 2.0
B dq -5.0
C dq -3.0
numSqrt dq 0.0
addDb dq 0.0
subtractDb dq 0.0
X1 dq 0.0
X2 dq 0.0

fourDb dq 4.0
twoDb dq 2.0
negaOneDb dq -1.0


section .text
global main
main:
    mov rbp, rsp; for correct debugging
    
    movsd xmm1, [A]
    movsd xmm2, [B]
    movsd xmm3, [C]
    
    movsd xmm4, [numSqrt]
    movsd xmm5, [fourDb]
    movsd xmm6, [twoDb]
    movsd xmm7, [negaOneDb]
    movsd xmm8, [addDb]
    movsd xmm9, [subtractDb]
    
    movsd xmm10, [X1]
    movsd xmm11, [X2]

    
    ; X1 --------------------------
    ; NUMERATOR
    
    ; b^2
    mulsd xmm2, xmm2
    ; 4ac
    mulsd xmm1, xmm3
    mulsd xmm1, xmm5
    ; b^2 - 4ac
    subsd xmm2, xmm1
    ; sqrt b^2 - 4ac
    sqrtsd xmm4, xmm2
    
    ; FOR X1:
    ; -b + sqrt b^2 - 4ac
    movsd xmm2, [B]
    mulsd xmm2, xmm7
    addsd xmm2, xmm4
    movsd xmm8, xmm2
    
    ; FOR X2:
    ; -b - sqrt b^2 - 4ac
    movsd xmm2, [B]
    mulsd xmm2, xmm7
    subsd xmm2, xmm4
    movsd xmm9, xmm2
    
    ; DENOMINATOR
    
    ; 2a
    movsd xmm1, [A]
    mulsd xmm1, xmm6
    
    ; X1
    divsd xmm8, xmm1
    movsd xmm10, xmm8
    
    ; X2
    divsd xmm9, xmm1
    movsd xmm11, xmm9
    
    ; convert to integer
    ; X1
    cvtsd2si eax, xmm10
    ; X2
    cvtsd2si ebx, xmm11
    
    movsd xmm1, [A]
    movsd xmm2, [B]
    movsd xmm3, [C]
    cvtsd2si ecx, xmm1
    cvtsd2si edx, xmm2
    cvtsd2si r8d, xmm3
    
    
    ; PRINT VALUES
    PRINT_STRING "CONVERTED INPUT VALUES"
    NEWLINE
    PRINT_STRING "A: "
    PRINT_DEC 8, ecx
    NEWLINE
    PRINT_STRING "B: "
    PRINT_DEC 8, edx
    NEWLINE
    PRINT_STRING "C: "
    PRINT_DEC 8, r8d
    NEWLINE
    NEWLINE
    
    PRINT_STRING "CONVERTED OUTPUT VALUES"
    NEWLINE
    PRINT_STRING "X1: "
    PRINT_DEC 8, eax
    NEWLINE 
    PRINT_STRING "X2: "
    PRINT_DEC 8, ebx
    NEWLINE    
    
       
    xor rax, rax
    ret