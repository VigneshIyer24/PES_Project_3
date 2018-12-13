/*-------------------------------
 * pit.c
 * Project 3 by Vignesh Iyer
 * Date Created: 12/10/2018
 *
 *
 *-----------------------------*/

#include "pit.h"

void pit_init(void)
{
	// Enable PIT clock
	//SIM_SCGC6 |= SIM_SCGC6_PIT_MASK;

	// Enable Green LED clock and MUX
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
	PORTB_PCR10 = PORT_PCR_MUX(1);
	GPIOB_PDDR |= GPIO_PDDR_PDD_MASK;
	//GPIOB_PSOR |= (1 << LED_GREEN);


}

/*	Handles PIT interrupt if enabled
 *
 * 	Starts conversion in ADC0 with single ended channel 8 (PTB0) as input
 *
 * */
/*void PIT_IRQHandler(void)
{
	// Clear interrupt
	PIT_TFLG0 = PIT_TFLG_TIF_MASK;

	// Write to SC1A to start conversion with channel 0 PTB0
	ADC0_SC1A = (ADC_SC1_ADCH(ADC_CHANNEL) |
				 (ADC0_SC1A & (ADC_SC1_AIEN_MASK | ADC_SC1_DIFF_MASK)));

	// Toggle Green LED
	GPIOB_PTOR |= GPIO_PTOR_PTTO_MASK;
}*/
