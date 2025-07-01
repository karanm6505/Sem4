        .text
        .global _start
_start:
        LDR R0, =A            
        LDR R1, =POS          
        LDR R2, =NEG          

loop:   
        LDR R3, [R0], #4      
        CMP R3, #0            
        BEQ exit              

        CMP R3, #0            
        BLT store_neg         
        STR R3, [R1], #4      
        B loop                

store_neg:   
        STR R3, [R2], #4      
        B loop                

exit:   
        SWI 0x011             

        .data
A:      .word 1,2,3,4,-1,5,-2,-3,6,0  
POS:    .word 0,0,0,0,0,0,0,0,0,0     
NEG:    .word 0,0,0,0,0,0,0,0,0,0     

