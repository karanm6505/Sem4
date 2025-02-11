        .data
A:      .word 1,3,5,6,2,4,9,8,7
len:    .word 9

        .text
        .global _start

        LDR     R4, =A
        LDR     R5, =len
        LDR     R5, [R5]
        SUB     R5, R5, #1

bblsort:
        MOV     R6, #0
iloop:
        CMP     R6, R5
        BGE     done
        MOV     R7, #0
        LDR     R8, =A

jloop:
        LDR     R9, [R8]
        LDR     R10, [R8, #4]
        CMP     R9, R10
        BLE     no_swap

        STR     R10, [R8]
        STR     R9, [R8, #4]

no_swap:
        ADD     R8, R8, #4
        ADD     R7, R7, #1
        SUB     R9, R5, R6
        CMP     R7, R9
        BLT     jloop

        ADD     R6, R6, #1
        B       iloop

done:
        SWI     0x11

