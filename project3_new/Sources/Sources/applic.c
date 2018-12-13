/*-------------------------------
 * applic.c
 * Project 3 by Vignesh Iyer
 * Date Created: 12/8/2018
 *
 *
 *-----------------------------*/

#include "applic.h"
#include <stdint.h>
#include <stdlib.h>
#include "uart.h"
#include "MKL25Z4.h"
#include <math.h>
uint16_t high_value=0;
uint16_t decay_coeff=0.2;
void peak_data(uint16_t data,uint16_t decay_data)
{
	if(data>high_value)
	{
		high_value=data;
		UART0_D= high_value;
		for(int i=0;i<5000;i++);
	}
	else
	{
		data=0.2*decay_data;
		UART0_D= data;
		for(int i=0;i<5000;i++);
	}
}
