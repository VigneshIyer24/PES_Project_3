
#ifndef INCLUDES_APPLIC_H_
#define INCLUDES_APPLIC_H_
#include <stdint.h>

/*-----------------------------------------------------------------
 * Function name:void peak_data(uint16_t data,uint16_t decay_data)
 * This function takes data and decay_data as input which is current
 * data and the previous data and calculates data to be the value of
 * the decay data multiplied by the decay coefficient and prints to
 * UART. If the data is higher than the current peak, it simply prints
 * the highest of the two data on UART.
 * ----------------------------------------------------------------- */
void peak_data(uint16_t data,uint16_t decay_data);



#endif /* INCLUDES_APPLIC_H_ */
