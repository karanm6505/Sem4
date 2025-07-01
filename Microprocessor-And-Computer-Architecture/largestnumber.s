        .text
        .global _start
_start:
        LDR R0, =A            
        LDR R1, [R0], #4      
        LDR R2, [R0], #4      

loop:   
        CMP R2, #0            
        BEQ exit              
        CMP R1, R2            
        BGE skip              
        MOV R1, R2            

skip:   
        LDR R2, [R0], #4      
        B loop                

exit:   
        LDR R3, =LARGEST      
        STR R1, [R3]          
        SWI 0x011             

        .data
A:      .word 10,50,41,55,30,20,11,5,100,77,0  
LARGEST: .word 0                            

