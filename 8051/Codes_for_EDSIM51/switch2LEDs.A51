; This code reads switches sw4 to sw7 on P2 and accordingly 
; turns ON or OFF LEDs 0 to 3 on P1
;
; Note: set update freq to 5
;
        ;
        ORG     0
        SJMP    START

        ORG     0030H
START:  MOV     SP,#60H
        ;
LP1:    MOV     A,P2
        SWAP    A
        ORL     A,#0F0H
        MOV     P1,A  	
        SJMP    LP1
        END
