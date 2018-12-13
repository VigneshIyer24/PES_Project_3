/*-------------------------------
 * Project 3 by Vignesh Iyer
 * Date Created: 12/5/2018
 *
 *
 *-----------------------------*/




#include "MKL25Z4.h" /* include peripheral declarations */
#include "adc.h"
#include "pit.h"
#include "dma.h"
#include "uart.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "applic.h"
uint32_t baud=57600;
extern char ready;

int main(void)
{
	int i;
	uint16_t avg, high, prev_samp;
	high=0;
	avg = 0;
	ready = 0;


	adc_init();
	pit_init();
//	adc_read(0);
	uart_init(baud);

	dma_init();

	for(;;)
	{
		/*--------------------------------------------------------------------
		 * This fills the buffer with ADC_READING as the buffer size i.e. 64
		 *--------------------------------------------------------------------*/
		if(ready < ADC_READING)
		{
			for(i = 0; i < ADC_READING; i++)
			{
				value[i]=adc_read(0);
				avg = value[i];
				GPIOB_PTOR |= GPIO_PTOR_PTTO_MASK;

				if(i>0)
				{
					prev_samp=value[i-1];
				}
				/*ready=1;
				if(ready==1)
				{
				peak_data(avg,prev_samp);
				}*/
				UART0_D=avg;
			}



			ready = 0;
		}




}

	return 0;
	}



