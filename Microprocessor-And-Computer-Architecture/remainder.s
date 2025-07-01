.data
A: .word 10
B: .word 3

.text
LDR R0,=A
LDR R1,=B
LDR R2,[R0]
LDR R3,[R1]

UP: SUB R4,R2,R3
    CMP R4,#0
    BGT DOWN
    BEQ QUIT
    ADDLT R4,R4,R3
    B QUIT
DOWN: MOV R2,R4
      B UP
QUIT: SWI 0X011
