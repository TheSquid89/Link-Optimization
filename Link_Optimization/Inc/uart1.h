/*
 * uart1.h
 *
 *  Created on: Feb 9, 2024
 *      Author: A
 */

#ifndef UART1_H_
#define UART1_H_
#define SR_RXNE			(1U<<5)
#include "stm32f4xx.h"
#include <stdint.h>

void Uart1_Init(void);
char Uart1_Read(void);
void Uart1_Write(int ch);

#endif /* UART1_H_ */
