        .text

        LDR R0, =A          ; Load base address of A
        LDR R1, =B          ; Load base address of B
        LDR R2, =N          ; Load number of elements
        LDR R2, [R2]        ; Dereference to get the actual value
        MOV R3, #0          ; R3 will hold the final convolution sum

LOOP:                      ; Label should be at the start of the line
        LDR R4, [R0], #4    ; Load element from A and increment address
        LDR R5, [R1], #4    ; Load element from B and increment address
        MUL R6, R4, R5      ; Multiply A[i] * B[i]
        ADD R3, R3, R6      ; Accumulate result

        SUBS R2, R2, #1     ; Decrement loop counter
        BNE LOOP            ; If not zero, continue loop

        ; Store the result at RESULT location
        LDR R7, =RESULT
        STR R3, [R7]

        SWI 0x11            ; Software interrupt to stop execution

        .data
A:      .word 1, 2, 3, 4
B:      .word 5, 6, 7, 8
N:      .word 4            ; Number of elements
RESULT: .word 0            ; Memory to store result

