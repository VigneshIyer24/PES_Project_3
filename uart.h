


#include<stdint.h>
#include <stdlib.h>
#ifndef INCLUDES_UART_H_
#define INCLUDES_UART_H_
//#include "circbuf.h"
/*------------------------------------------------------------
 * uart_init(uint32_t baud)
 * This function uses the baud rate for the given initiates
 * the uart process
 *------------------------------------------------------------*/
void uart_init(uint32_t baud_rate);
/*-------------------------------------------------------------
 * UART0_IRQHandler()
 * This function uses interupts for calculation and display
 * the characters on the  terminal
 */
void UART0_IRQHandler();
void uart_send(uint16_t data);


uint8_t uart_recieve_data (void);

void uart_send_one(uint8_t data);


#endif /* INCLUDES_UART_H_ */


