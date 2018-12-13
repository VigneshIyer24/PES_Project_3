

#ifndef ADC_H_
#define ADC_H_

#include "MKL25Z4.h"
#include <stdint.h>

/* -------------------------------------------------------
 * Function name: void adc_init(void)
 * This function does not take any inputs and initializes
 * the ADC with the clock, clock division, ADC channel, as
 * well as the DMA interrupt enable
 * -------------------------------------------------------- */
void adc_init(void);

/*----------------------------------------------------------
 * Function name adc_read(unsigned char value_mask)
 * This function takes input with values from 0 to 3 which
 * starts the conversion process and only gets out when the
 * conversion is complete. This function returns ADC0_RA on
 * Successful completion.
 * --------------------------------------------------------- */
uint16_t adc_read(unsigned char value_mask);

#endif /* ADC_H_ */
