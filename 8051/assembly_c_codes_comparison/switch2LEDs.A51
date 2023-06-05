;
; switch LEDs P1.0 through P1.3 ON/OFF with switches P14 through P17
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
LP1:    MOV     A,P1
        SWAP    A
        ORL     A,#0F0H
        MOV     P1,A  	
        SJMP    LP1
        END
