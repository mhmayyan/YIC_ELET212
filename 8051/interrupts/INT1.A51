SELECT  EQU     0FC48H
IO_SEL  EQU     10011100B

        ORG     0000H
        SJMP    START

        ORG     0013H
        SJMP    INT_1

        ORG     0030H
START:  MOV     SP,#60H

        MOV     A,#IO_SEL
        MOV     DPTR,#SELECT
        MOVX    @DPTR,A
        ;
        MOV     A,#11111110B
        MOV     P1,A
        ;
        SETB    IT1
        SETB    EX1
        SETB    EA
WAIT:   SJMP    WAIT

INT_1:  RL      A
        ORL     A,#0F0H
        CJNE    A,#0FFH,SKIP
        MOV     A,#0FEH
SKIP:   MOV     P1,A
        RETI
        END
        
