.text
	LDR R4,=F
	MOV R0,#5
	MOV R1,#10
	MOV R2,#1
	MOV R3,#4

	SUB R13,R13,#16
	STR R0,[R13,#12]
	STR R1,[R13,#8]
	STR R2,[R13,#4]
	STR R3,[R13,#0]

	BL example
	STR R0,[R4]
	SWI 0x011
	
	example:
	LDR R5,[R13,#0]
        LDR R6,[R13,#4]
        LDR R7,[R13,#8]
        LDR R8,[R13,#12]

	ADD R9,R7,R8 ; G+H
	ADD R10,R5,R5 ; I+J
	SUB R11,R9,R10

	MOV R0,R4
	ADD R13,R13,#12
	MOV PC,LR

.data
	F: .WORD 0

.end
