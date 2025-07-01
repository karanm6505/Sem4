        .text
        .global _start
_start:
        LDR R0, =ARRAY        
        LDR R1, =NEGSUM       
        MOV R2, #0            

loop:   
        LDR R3, [R0], #4      
        CMP R3, #0            
        BEQ exit              

        CMP R3, #0            
        BGE loop              

        ADD R2, R2, R3        
        B loop                

exit:   
        STR R2, [R1]          
        SWI 0x011             

        .data
ARRAY:  .word 1,2,3,4,-1,5,-2,-3,6,0  
NEGSUM: .word 0                       

