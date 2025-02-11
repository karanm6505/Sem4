        .text
_start:
        LDR R0, =NUMBER    ; Load the address of the 32-bit number
        LDR R1, [R0]       ; Load the actual 32-bit number into R1
        MOV R2, #0         ; R2 will store the sum of BCD digits

LOOP:  
        CMP R1, #0         ; Check if R1 is zero (all digits processed)
        BEQ DONE           ; If yes, exit loop

        AND R3, R1, #0xF   ; Extract the least significant BCD digit
        ADD R2, R2, R3     ; Add extracted digit to sum

        MOV R1, R1, LSR #4 ; Shift right by 4 bits to process the next digit
        B LOOP             ; Repeat until all digits are processed

DONE:
        LDR R4, =RESULT    ; Load address of RESULT
        STR R2, [R4]       ; Store final sum in RESULT

        SWI 0x11           ; Software interrupt to stop execution

        .data
NUMBER: .word 0x00000788   ; 32-bit BCD number (Example: 788 → 7+8+8 = 23)
RESULT: .word 0            ; Memory location to store sum

