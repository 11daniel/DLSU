%include "io64.inc"

section .data
    input_prompt db "Enter text: ", 0       ; Prompt message for input
    input_buffer times 20 db 0              ; Buffer to hold user input (up to 20 characters)
    var1 db 0
    var2 db 0
    key times 20 db 0                      ; Key storage, size based on the word length

section .text
global main
main:
    mov rbp, rsp; for correct debugging
    ; Display input prompt
    ;PRINT_STRING input_prompt

    ; Read user input into input_buffer (up to 20 characters)
    GET_STRING input_buffer, 20
    GET_DEC 8, var1
    GET_DEC 8, var2
    ; Prepare to print user input as ASCII
    ; PRINT_STRING "Input Text (in ASCII): "
    mov rsi, input_buffer

print_ascii_loop:
    ; Load the byte at [rsi] into al
    mov al, byte [rsi]
    
    ; Check for null terminator (end of string)
    cmp al, 0
    je done_ascii  ; If null terminator is found, jump to end

    ; Print the character in al
    PRINT_CHAR al
    
    ; Move to the next character
    inc rsi
    jmp print_ascii_loop    ; Repeat the loop

done_ascii:
    NEWLINE

    ; Print input as hex
    ; PRINT_STRING "Input Text (in HEX): "
    mov rsi, input_buffer

print_hex_loop:
    ; Load the byte at [rsi] into al
    mov al, byte [rsi]
    
    ; Check for null terminator (end of string)
    cmp al, 0
    je done_hex  ; If null terminator is found, jump to end

    ; Call function to print the byte in hex
    call PRINT_HEX_BYTE
    
    ; Move to the next character
    inc rsi
    jmp print_hex_loop    ; Repeat the loop

done_hex:
    NEWLINE

    ; Initialize variables for the key generation
    movzx rax, byte [var1]       
    movzx rbx, byte [var2]       
    mov rcx, 2                   ; Starting index for key array

    ; Store the first two keys
    and rax, 0xff                ; Get lower 8 bits of n1
    mov [key], al                ; Store in key[0]

    and rbx, 0xff                ; Get lower 8 bits of n2
    mov [key + 1], bl            ; Store in key[1]

fib:
    ; Calculate keys based on the length of the input word
    mov rdx, input_buffer        ; rdx points to the input buffer
    sub rsi, rsi                 ; Reset rsi to zero
.next_key:
    cmp byte [rdx + rsi], 0      ; Check for end of string
    je done_fib                  ; If end of string, exit loop

    ; Calculate n1 += n2
    add rax, rbx                 ; n1 = n1 + n2

    ; Get lower bits of the new n1 and store in key[rcx]
    and rax, 0xff                ; Get lower 8 bits of n1
    mov [key + rcx], al          ; Store in key[rcx]

    ; Swap n1 and n2
    xchg rax, rbx                ; Swap n1 and n2

    ; Increment index and continue loop
    inc rcx
    inc rsi                      ; Move to the next character
    jmp .next_key

done_fib:
    NEWLINE

    ; Display generated key in HEX
    ; PRINT_STRING "KEY (in Hex): "
    mov rsi, key                 ; Move to key for printing

print_key_hex_loop:
    mov al, byte [rsi]
    cmp al, 0
    je done_key_hex              ; End of keys

    call PRINT_HEX_BYTE
    inc rsi
    jmp print_key_hex_loop

done_key_hex:
    NEWLINE

    ; XOR Encryption of input text with key
    mov rsi, input_buffer           ; rsi points to the input buffer
    mov rdi, input_buffer           ; Reuse the same buffer to store "encrypted" output
    mov rcx, 0                      ; Index for accessing the key

encrypt_loop:
    mov al, byte [rsi]              ; Load input byte
    cmp al, 0                       ; Check for null terminator
    je done_encrypt                 ; If end of string, exit loop

    mov bl, [key + rcx]             ; Load key byte
    xor al, bl                      ; XOR input byte with key byte
    mov [rdi], al                   ; Store encrypted byte

    inc rsi                         ; Move to next input byte
    inc rdi                         ; Move to next output byte
    inc rcx                         ; Move to the next key byte
    cmp rcx, 20                    ; Optional: Loop over the key if necessary
    jl encrypt_loop                 ; Continue if there's more input

done_encrypt:
    NEWLINE

    ; Display encrypted text in HEX
    ; PRINT_STRING "Encrypted Text (in Hex): "
    mov rsi, input_buffer

print_encrypted_hex_loop:
    mov al, byte [rsi]
    cmp al, 0
    je done_encrypted_hex

    call PRINT_HEX_BYTE
    inc rsi
    jmp print_encrypted_hex_loop

done_encrypted_hex:
    NEWLINE

    ; Display encrypted text in ASCII
    ; PRINT_STRING "Encrypted Text (in ASCII): "
    mov rsi, input_buffer

print_encrypted_ascii_loop:
    mov al, byte [rsi]
    cmp al, 0
    je done_encrypted_ascii

    PRINT_CHAR al
    inc rsi
    jmp print_encrypted_ascii_loop

done_encrypted_ascii:
    NEWLINE

    xor rax, rax
    ret

; Function to print a single byte (in AL) as two hexadecimal characters
PRINT_HEX_BYTE:
    push rax                  ; Save rax as we'll modify it

    ; Prepare upper nibble in AL for ASCII conversion
    mov ah, al                ; Copy AL to AH
    shr al, 4                 ; Shift AL right by 4 to get upper nibble
    and ah, 0x0F              ; Mask AH to get lower nibble
    add ax, 0x3030            ; Add 0x3030 to make both nibbles ASCII-compatible

    ; Adjust upper nibble if needed (for 'A'-'F')
    cmp al, 0x39              ; Check if AL > '9'
    jbe .print_upper_digit
    add al, 7                 ; Adjust for 'A'-'F' if AL > '9'
.print_upper_digit:
    PRINT_CHAR al             ; Print the upper hex digit in AL

    ; Adjust lower nibble if needed (for 'A'-'F')
    cmp ah, 0x39              ; Check if AH > '9'
    jbe .print_lower_digit
    add ah, 7                 ; Adjust for 'A'-'F' if AH > '9'
.print_lower_digit:
    mov al, ah                ; Move AH to AL to avoid high register issue
    PRINT_CHAR al             ; Print the lower hex digit in AL
    PRINT_STRING " "
    
    pop rax                   ; Restore rax
    ret
