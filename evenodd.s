.text

        LDR R0, =ARRAY
        LDR R1, =LOCA
        LDR R2, =LOCB

loop:    LDR R3, [R0], #4
        CMP R3, #0
        BEQ exit

        AND R4, R3, #1
        CMP R4, #0
        BEQ store_even

store_odd:
        STR R3, [R2], #4
        B loop

store_even:
        STR R3, [R1], #4
        B loop

exit:    SWI 0x011


.data
ARRAY: .word 10,20,31,39,30,41,42,69
LOCA: .word 0,0,0,0,0,0,0,0
LOCB: .word 0,0,0,0,0,0,0,0
