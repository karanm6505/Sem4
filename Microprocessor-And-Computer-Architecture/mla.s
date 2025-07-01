.text
LDR R5,=A
LDR R6,=B
LDR R7,=C
MOV R3,#3
MOV R4,#0
Loop:
	LDR R1,[R5],#4
	LDR R2,[R6],#4
	MLA R4,R1,R2,R4 ;c = c + a*b (similar to matrix multiplication)
	;does A x B matrix A(1x3) and B(3x1) leads to C(1x1)
	STR R4,[R7],#4
	SUB R3,R3,#1
	TEQ R3,#0
	BNE Loop
	SWI 0x011

.data
A: .word 1,3,5
B: .word 2,4,6
C: .word 0

