.data
a: .word 1,2,3,4,5,6,7,8,9

.text
ldr r9,=a
mov r1,#3
mov r2,#3
mov r3,#0
mov r4,#1

mla r5,r3,r2,r4
mov r6,r5,lsl #2
add r6,r9,r6
swi 0x011

