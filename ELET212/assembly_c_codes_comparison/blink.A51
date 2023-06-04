; blink pin 0 on port 1
;
SELECT  EQU     0FC48H
IO_SEL  EQU     10011110B
        ;
        ORG     0
        SJMP    START

        ORG     0030H
START:  MOV     SP,#60H	; set the stack pointer to point to RAM address 0x60

        ;set up the training kit decoder
        MOV     A,#IO_SEL
        MOV     DPTR,#SELECT
        MOVX    @DPTR,A


LP1:    CPL     P1.0    ; toggle bit 0 on port 1
        CALL    DELAY   ; call a delay subruotine
        SJMP    LP1

;delay subroutine
DELAY:  MOV     R0,#2
DELAY1: MOV     R1,#0
DELAY2: MOV     R2,#0
DELAY3: NOP
        DJNZ    R2,DELAY3
        DJNZ    R1,DELAY2
        DJNZ    R0,DELAY1
        RET
        END
