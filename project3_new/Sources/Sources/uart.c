/*-------------------------------
 * uart.c
 * Project 3 by Vignesh Iyer
 * Date Created: 11/27/2018
 *
 *
 *-----------------------------*/

#include"MKL25Z4.h"
#include"uart.h"
#include<stdint.h>
#include<stdlib.h>
uint8_t rec1;
//buffer *reception;
//buffer *sender;
uint8_t *point;
//error_msg p;

void uart_init(uint32_t baud_rate)
{
	uint16_t baud_divide;


	//Set gate clock  for PORTA
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;

	//Enable clock for UART0 and set clock source as MCGCLKFLL
	SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;
	SIM_SOPT2 |= SIM_SOPT2_UART0SRC(1);

	// Set the alternate function for PORTA as UART0
	PORTA_PCR1 = PORT_PCR_MUX(2);
	PORTA_PCR2 = PORT_PCR_MUX(2);

	// Disable tx and rx before editing registers of UART0
	UART0_C2=0x00;
	UART0_C1=0x00;





	/* Calculate baud_divide for sbr register and set baud rate */
	baud_divide= (uint16_t)(DEFAULT_SYSTEM_CLOCK/(baud_rate *16));
	UART0_BDH |= (baud_divide >> 8) & UART0_BDH_SBR_MASK;
	UART0_BDL = (baud_divide & UART0_BDL_SBR_MASK);



	//Set NVIC interrupts and CPU interrupts
	NVIC_EnableIRQ(UART0_IRQn);
	NVIC_SetPriority(UART0_IRQn,2);

	UART_C2_REG(UART0_BASE_PTR) |= UART_C2_RIE_MASK; //Setup receiver interrupt
//	UART_C2_REG(UART0_BASE_PTR) |= UART_C2_TIE_MASK;
	//__enable_irq();

    UART_C2_REG(UART0_BASE_PTR) |= (UART_C2_TE_MASK | UART_C2_RE_MASK ); //Switch on transmitter and receiver
  }

void uart_send(uint16_t data){

	UART0_D = data;

}



void uart_send_length(uint8_t *data, uint32_t length){

	uint8_t i;

	for(i=0;i<length;i++){

#ifndef INTERRUPT

	while(!(UART0_S1_REG(UART0_BASE_PTR) & UART0_S1_TDRE_MASK));

#endif

	UART0_D_REG(UART0_BASE_PTR) = *data;

	data++;

	}

}



uint8_t uart_recieve_byte (void){



    return UART0_D_REG(UART0_BASE_PTR);

}

void UART0_IRQHandler(void)

{

//	__disable_irq();
	//__asm("cpsid i");
	if ((UART0_S1 & UART0_S1_RDRF_MASK)){

        rec1 = UART0_D;
       // p=buf_add(reception,rec1);
     //UART0_C2&=~UART0_C2_RIE_MASK;
     //UART0_C2 |= UART0_C2_TIE_MASK;

	}
   else	if ((UART0_S1 & UART0_S1_TDRE_MASK))
   {
	/*   p= buf_add(sender,rec1);
	   p=buf_delete(sender,&rec1);
	   //UART0_D = rec1;
	  // uart_send_byte(*sender.tail);
*/
	   UART0_C2 &= ~UART0_C2_TIE_MASK;
	   UART0_C2 |=UART0_C2_RIE_MASK;

    }

//	__enable_irq();
	//__asm("cpsie i");

}
