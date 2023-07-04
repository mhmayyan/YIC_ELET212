      ;
      ; shift an LED from P1.0 to P1.3 repeatedly
      ;
       
              ;
              ORG     0
0000|         SJMP    START
       
              ORG     0030H
0030| START:  MOV     SP,#60H
              ;
0033|         MOV     A,#11111110B
0035| LP1:    MOV     P1,A
0037|         CALL    DELAY
0039|         RL      A
003A|         ORL     A,#0F0H
003C|         CJNE    A,#0FFH,LP1
003F|         MOV     A,#11111110B
0041|         SJMP    LP1
       
0043| DELAY: MOV     R2,#2
0045| DELAY3:	DJNZ    R2,DELAY3
0047|         RET
              END
