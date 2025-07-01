.text
    

    MOV  r0, #0x20      ; Load r0 with the value 0x1234
    LDR  r1, =0x1000      ; Load r1 with the base memory address 0x1000

    STR  r0, [r1, #4]!    ; Store r0 at (r1 + 4), then update r1 = r1 + 4
    LDR r2, [r1]
   

