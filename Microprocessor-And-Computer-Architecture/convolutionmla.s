        .text

        LDR R0, =A          ; Load base address of A
        LDR R1, =B          ; Load base address of B
        LDR R2, =N          ; Load number of elements
        LDR R2, [R2]        ; Dereference to get the actual value
        MOV R3, #0          ; R3 will hold the final convolution sum

LOOP:                      
        LDR R4, [R0], #4    ; Load element from A and increment address
        LDR R5, [R1], #4    ; Load element from B and increment address
        MLA R3, R4, R5, R3  ; Multiply A[i] * B[i] and accumulate in R3

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

