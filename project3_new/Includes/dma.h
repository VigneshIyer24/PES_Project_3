

#ifndef DMA_H_
#define DMA_H_

#include "MKL25Z4.h"

#define  ADC_READING 64
uint16_t  value[ADC_READING];
char ready;
/*---------------------------------------------------
 * Function name: void dma_init(void)
 * This function initializes the DMA with modes set
 * according to the given parameters of the ADC
 * -------------------------------------------------- */
void dma_init(void);

/*--------------------------------------------------------
 * Function name: void DMA0_IRQHandler(void)
 * This function clears the flag when the DMA interrupt
 * takes place and thus resetting the value of registers
 * in order for the interrupt to start.
 * -------------------------------------------------------- */
void DMA0_IRQHandler(void);

#endif /* DMA_H_ */
