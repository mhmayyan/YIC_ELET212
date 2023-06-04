;
; shift an LED from P1.0 to P1.3 repeatedly
;

SELECT  EQU     0FC48H
IO_SEL  EQU     10011110B
        ;
        ORG     0
        SJMP    START

        ORG     0030H
START:  MOV     SP,#60H
        MOV     A,#IO_SEL
        MOV     DPTR,#SELECT
        MOVX    @DPTR,A
        ;
        MOV     A,#11111110B
LP1:    MOV     P1,A
        CALL    DELAY
        RL      A
        ORL     A,#0F0H
        CJNE    A,#0FFH,LP1
        MOV     A,#11111110B
        SJMP    LP1

DELAY:  MOV     R0,#2
DELAY1: MOV     R1,#0
DELAY2: MOV     R2,#0
DELAY3: NOP
        DJNZ    R2,DELAY3
        DJNZ    R1,DELAY2
        DJNZ    R0,DELAY1
        RET
        END
