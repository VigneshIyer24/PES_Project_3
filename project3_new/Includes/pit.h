

#ifndef PIT_H_
#define PIT_H_

#include "MKL25Z4.h"
#include "adc.h"

#define ADC_CHANNEL 0 // Channel 8 (PTB0)
#define LED_GREEN  19 // PTB19

/*------------------------------------------------------
 * Function name:void pit_init(void)
 * This function initializes the GPIO pins to be set
 * to output mode and so as to use the GPIO for toggling
 *--------------------------------------------------------*/
void pit_init(void);



#endif /* PIT_H_ */
