/*
 * systick.h
 *
 *  Created on: Jan 17, 2024
 *      Author: A
 */
//void systickDelayMs(int delay);
#include <stdbool.h>
#include "tim.h"
void SysTick_Init(void);
void SysTick_Handler(void);
void delay (uint32_t T);
void SysTick_Interrupt_Handler(void);
uint32_t get_tick();
extern volatile bool heartbeat;
extern volatile uint32_t msTicks;
extern uint32_t heart_count;

#ifndef SYSTICK_H_
#define SYSTICK_H_



#endif /* SYSTICK_H_ */
