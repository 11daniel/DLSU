%include "io64.inc" 
section .data 
STRVAR db "acttccgtactgtt", "ggcaaagcgcttat", "ccttattatatcct", 0
KOUNTC db 0
KOUNTG db 0
DNALEN db 0
section .text 
    global CMAIN 
    CMAIN: 
        xor rax, rax
        xor rbx, rbx
        xor rcx, rcx
        mov rdx, 0x00
        mov r8b, 'c'
        mov r9b, 'g'
    
    CHECK:
        cmp rdx, [STRVAR+rcx]
        je FINIS
        inc rcx
        jmp L1
        
    L1:
        cmp r8b, [STRVAR+rcx-1]
        jne L2
        inc rax
        
    L2:
        cmp r9b, [STRVAR+rcx-1]
        jne CHECK
        
        PRINT_CHAR [STRVAR+rcx-1]
        inc rbx
        jmp CHECK
        
    FINIS:
        mov [DNALEN], cl
        mov [KOUNTC], al
        mov [KOUNTG], bl
        NEWLINE
        PRINT_STRING "DNALEN: "
        PRINT_DEC 1, [DNALEN]
        NEWLINE
        PRINT_STRING "KOUNTC: "
        PRINT_DEC 1, [KOUNTC]
        NEWLINE
        PRINT_STRING "KOUNTG: "
        PRINT_DEC 1, [KOUNTG]
    
        
    xor rax, rax 
    ret