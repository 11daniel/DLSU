; CLEMENTE, Daniel Gavrie Y. S18

%include "io64.inc"

section .data
LIST dd 1.5, 2.5, 3.5, 0.0          ; LIST containing floating point values

section .text
global main

main:
    mov rbp, rsp                     ; Set up base pointer for debugging
    lea rbx, [LIST]                  ; Load address of LIST into rbx (use lea for 64-bit)

    xor rcx, rcx                     ; Initialize rcx to 0 (used as an index)
    
L1:
    movss xmm1, [rbx + rcx * 4]      ; Load the current element from LIST into xmm1
    movss xmm2, xmm1                 ; Copy xmm1 to xmm2
    xorps xmm3, xmm3                 ; Zero xmm3 to use for comparison
    ucomiss xmm1, xmm3               ; Compare xmm1 with 0.0
    jz end                           ; If xmm1 is zero, end the loop
    
    cvtss2si eax, xmm1               ; Convert the float in xmm1 to integer in eax
    PRINT_DEC 8, eax                 ; Print integer in eax
    NEWLINE                          ; Print newline after the integer output
    
    inc rcx                          ; Increment rcx to move to the next element
    jmp L1                           ; Repeat the loop
    
end:
    xor rax, rax                     ; Exit code 0
    ret
