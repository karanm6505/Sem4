.data
	a: .word 10,20,30,60,40,50
.text
	ldr r1,=a
	ldr r0,[r1]
	mov r3,#0
loop: 
	ldr r2,[R1,#4]!
	cmp r0,r2
	blt less
	l1: add r3,r3,#1
	cmp r3,#4
	bne loop
	b exit

less: mov r0,r2
	b l1
exit:
swi 0x011
.end
