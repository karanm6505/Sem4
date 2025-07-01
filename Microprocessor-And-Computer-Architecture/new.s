.text
mov r1, #3
BEQ assignment
add r2, r0, r1
add r2,r0,r1
add r0,r0,#1
swi 0x011
assignment:
mov r0, #2
bx lr
.end
