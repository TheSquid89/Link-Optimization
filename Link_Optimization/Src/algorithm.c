/*
 * algorithm.c
 *
 *  Created on: Feb 12, 2024
 *      Author: A
 */

#include "algorithm.h"
#include "Servo_Move.h"
#include "stm32f4xx.h"
#include <stdint.h>
#include "uart1.h"



/**********************Generating Random RSSI values for Testing Purposes*******************************/

signed char d;
int avg_rssi;
int Xrssi;
int Yrssi;

int random_index(int min, int max) {
    return min + rand() % (max - min + 1);
}

uint32_t Read_RSSI(void) // Change return type to uint32_t
{
//	if(USART1->SR & SR_RXNE != 0)
//	{
		d = Uart1_Read();
		printf("<%i>\n\r", d);
//	}


}

int rssi;

uint32_t Average_Rssi(void)
{
	for(int i = 0; i < 2; i++)
	{
		d = Uart1_read();
		avg_rssi += d;
	}
	avg_rssi = rssi/3;
}

