        .text
        .global _start
_start:
        LDR R0, =N            
        LDR R0, [R0]          
        LDR R1, =FIB          
        MOV R2, #0            
        MOV R3, #1            
        STR R2, [R1], #4      
        STR R3, [R1], #4      

        SUBS R0, R0, #2       
        BLE exit              

loop:   
        ADD R4, R2, R3        
        STR R4, [R1], #4      
        MOV R2, R3            
        MOV R3, R4            
        SUBS R0, R0, #1       
        BLAL loop

		BX R10  ;branch ex
		BLX R10 ;branch ex w link

exit:   
        SWI 0x011             

        .data
N:      .word 10             
FIB:    .word 0,0,0,0,0,0,0,0,0,0  

