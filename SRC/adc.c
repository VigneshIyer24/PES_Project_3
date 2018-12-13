/*-------------------------------
 * adc.c
 * Project 3 by Vignesh Iyer
 * Date Created: 12/5/2018
 *
 *
 *-----------------------------*/



#include "adc.h"
#include <stdint.h>

/*	adc_init()
 * Calibrates and initializes adc to perform single conversions and generate
 * DMA requests at the end of the conversion
 *
 * */
void adc_init(void)
{
	// Enable clocks
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;	// ADC 0 clock
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;	// PTB0 clock



	// Configure ADC
	ADC0_CFG1 = 0; // Reset register
	ADC0_CFG1 |= (ADC_CFG1_MODE(3)  |  	// 16 bits mode
				  ADC_CFG1_ADIV(1)) ;	// Clock divide by 2 (10-12.5 MHz)


	ADC0_SC3 |= ADC_SC3_AVGE_MASK |		// Enable HW average
					ADC_SC3_AVGS(3)|ADC_SC3_ADCO_MASK;   		// Set HW average of 32 samples

	ADC0_SC2 |= ADC_SC2_DMAEN_MASK;
	//ADC0_SC1A |= ADC_SC1_ADCH(31); // Disable module
}



/*unsigned short	adc_read(unsigned char ch)
 * 	Reads the specified adc channel and returns the 16 bits read value
 *
 * 	ch -> Number of the channel in which the reading will be performed
 * 	Returns the -> Result of the conversion performed by the adc
 *
 * */
uint16_t adc_read(unsigned char value_mask)
{
	ADC0_SC1A = (value_mask & ADC_SC1_ADCH_MASK) |
				(ADC0_SC1A & (ADC_SC1_AIEN_MASK | ADC_SC1_DIFF_MASK));     // Write to SC1A to start conversion

	//while(ADC0_SC2 & ADC_SC2_ADACT_MASK); 	 // Conversion in progress
	while(!(ADC0_SC1A & ADC_SC1_COCO_MASK)); // Run until the conversion is complete
	return ADC0_RA;

}
