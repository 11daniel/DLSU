%include "io64.inc"
section .data
    message times 20 db 0 ; Define string with null terminator
section .text
global main
main:
    ;write your code here
    GET_STRING message, 20
    mov rsi, message

print_loop:
    ; Load the byte at [rsi] into al
    mov al, byte [rsi]
    
    ; Check for null terminator (end of string)
    cmp al, 0
    je end_loop       ; If null terminator is found, jump to end

    ; Print the character in al
    PRINT_CHAR al
    
    ; Move to the next character
    inc rsi
    jmp print_loop    ; Repeat the loop

end_loop:
    ; Exit the program
    xor rax, rax
    ret