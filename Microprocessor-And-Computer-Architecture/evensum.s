        .text
        .global _start
_start:
        LDR R0, =ARRAY        
        LDR R1, =EVENSUM      
        MOV R2, #0            

loop:   
        LDR R3, [R0], #4      
        CMP R3, #0            
        BEQ exit              

        AND R4, R3, #1        
        CMP R4, #0            
        BNE loop              

        ADD R2, R2, R3        
        B loop                

exit:   
        STR R2, [R1]          
        SWI 0x011             

        .data
ARRAY:  .word 15,10,12,13,9,45,16,8,25,33,0  
EVENSUM: .word 0                             
