.text
MOV R1, #10
MOV R2, #2
gcd:
	CMP r1, r2
	BEQ complete
	BLT lessthan
	SUB r1, r1, r2
	B gcd
lessthan:
	SUB r2, r2, r1
	B gcd
complete:
	SWI 0x011
.end
