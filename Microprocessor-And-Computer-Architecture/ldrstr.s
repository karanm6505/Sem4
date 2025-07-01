.text
    MOV R0, #100    ; Assume R0 holds some value (e.g., 100)
    MOV R1, R0      ; Load the "address" of R0 into R1 (copy value)
    LDR R2, [R1,#4]    ; Load the value stored at the address in R1 into R2



