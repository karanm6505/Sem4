        .text
        .global _start
_start:
        MOV R0, #72           
        MOV R1, #0            

        ADD R1, R1, R0, LSL #5  
        ADD R1, R1, R0, LSL #2  
        ADD R1, R1, R0, LSL #1  

        LDR R2, =RESULT       
        STR R1, [R2]          
        SWI 0x011             

        .data
RESULT: .word 0              

