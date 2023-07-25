#include    <win51.h>

#define     SELECT     (*( unsigned char*)(0x2fc48))

/*****************************************************/
/*****************************************************/
/********  Code Example for Using INT0 *********/
/*****************************************************/
/*****************************************************/

void    main( void )
{
       SELECT = 0x??;

       IT0 = 1; // 1 for hi to low (falling) edge, 0 for level change from high to low
       EX0 = 1; // activate INT0
       EA = 1 ; // enable all activated interrupts

       while(1)
       {
          /* add the main routine here */
       }
}

void EXINT0_ISR(void) interrupt 0
{
	/* ISR for INT1 */
}



/*****************************************************/
/*****************************************************/
/********  Code Example for Using INT1 *********/
/*****************************************************/
/*****************************************************/

void    main( void )
{
       SELECT = 0x??;

       IT1 = 1; // 1 for hi to low (falling) edge, 0 for level change from high to low
       EX1 = 1; // activate INT1
       EA = 1 ; // enable all activated interrupts

       while(1)
       {
          /* add the main routine here */
       }
}

void EXINT1_ISR(void) interrupt 2
{
	/* ISR for INT1 */
}


/*****************************************************/
/*****************************************************/
/********  Code Example for Using TIMER0 *********/
/*****************************************************/
/*****************************************************/

void    main( void )
{
       SELECT = 0x??;

	
	TMOD = ??; // select timer mode
	TH0 = ??; // timer 0 high byte of counter register
        TL0 = ??; // timer 0 low byte of counter register

        ET0 = 1; // activate timer 0 interrupt
        TR0 = 1; // start timer 0

        EA = 1 ; // enable all activated interrupts

       while(1)
       {
          /* add the main routine here */
       }
}

void TIMER0_ISR(void) interrupt 1
{
	/* Reload TIMER0 counter registers for modes other than mode 2 */
	TH0 = ??; // timer 0 high byte of counter register
        TL0 = ??; // timer 0 low byte of counter register

	/* ISR for TIMER0 */

}




/*****************************************************/
/*****************************************************/
/********  Code Example for Using TIMER1 *********/
/*****************************************************/
/*****************************************************/

void    main( void )
{
       SELECT = 0x??;

	
	TMOD = ??; // select timer mode
	TH1 = ??; // timer 1 high byte of counter register
        TL1 = ??; // timer 1 low byte of counter register

        ET1 = 1; // activate timer1 interrupt
        TR1 = 1; // start timer 1

        EA = 1 ; // enable all activated interrupts

       while(1)
       {
          /* add the main routine here */
       }
}

void TIMER1_ISR(void) interrupt 3
{
	/* Reload TIMER1 counter registers for modes other than mode 2 */
	TH1 = ??; // timer 1 high byte of counter register
        TL1 = ??; // timer 1 low byte of counter register

	/* ISR for TIMER1 */
}


