    .data
postfix_expr:   .asciz "23+4-"
stack:          .space 32
stack_top:      .word 0

    .text
    LDR R0, =postfix_expr
    LDR R1, =stack
    LDR R2, =stack_top
    MOV R3, #0

evaluate_postfix:
    LDRB R4, [R0], #1
    CMP R4, #0
    BEQ end_evaluation

    CMP R4, #'0'
    BGE is_digit

    BL pop
    MOV R5, R6
    BL pop
    MOV R6, R6

    CMP R4, #'+'
    BEQ do_addition
    CMP R4, #'-'
    BEQ do_subtraction

    B evaluate_postfix

is_digit:
    SUB R4, R4, #'0'
    BL push
    B evaluate_postfix

do_addition:
    ADD R6, R6, R5
    BL push
    B evaluate_postfix

do_subtraction:
    SUB R6, R6, R5
    BL push
    B evaluate_postfix

end_evaluation:
    BL pop
    MOV R7, #1
    SWI 0

push:
    STR R4, [R1, R3, LSL #2]
    ADD R3, R3, #1
    STR R3, [R2]
    BX LR

pop:
    SUB R3, R3, #1
    LDR R6, [R1, R3, LSL #2]
    STR R3, [R2]
    BX LR

