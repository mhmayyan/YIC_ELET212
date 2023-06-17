;	By Mohammad Mayyan
;	June 14, 2023
;
;	Function:
;	The purpose of the following code is to blink pin 0 on port 1.

        ORG     0
        SJMP    START

        ORG     0030H
; set the stack pointer to point to RAM address 0x60
START:  MOV     SP,#60H 

LP1:    CPL     P1.0    ; toggle bit 0 on port 1
        CALL    DELAY   ; call a delay subruotine
        SJMP    LP1	; simple jump to LP1 to repeat the process

; the delay subroutine
DELAY:  MOV     R0,#5
DELAY1:	DJNZ    R0,DELAY1
        RET
        END