/*
 * systick.c
 *
 *  Created on: Jan 17, 2024
 *      Author: Adam Robinson
 *
 */

#include "stm32f4xx.h"
#include "systick.h"

volatile uint32_t msTicks;
uint32_t heart_count = 0;

//******************************************************************************************
// Initialize SysTick
//******************************************************************************************
void SysTick_Init(void){
	// The RCC feeds the Cortex System Timer (SysTick) external clock with the AHB clock
	// (HCLK) divided by 8. The SysTick can work either with this clock or with the Cortex clock
	// (HCLK), configurable in the SysTick Control and Status Register.

	//  SysTick Control and Status Register
	SysTick->CTRL = 0;										// Disable SysTick IRQ and SysTick Counter

	// SysTick Reload Value Register - Note: HCLK = 80MHz (no divide by 8)
	SysTick->LOAD = 16000000 / 50;    // 1ms, Default clock

	// SysTick Current Value Register
	SysTick->VAL = 0;

	NVIC_SetPriority(SysTick_IRQn, 1);		// Set Priority to 1
	NVIC_EnableIRQ(SysTick_IRQn);					// Enable EXTI0_1 interrupt in NVIC

	// Enables SysTick exception request
	// 1 = counting down to zero asserts the SysTick exception request
	// 0 = counting down to zero does not assert the SysTick exception request
	SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;

	// Select processor clock
	// 1 = processor clock;  0 = external clock
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;

	// Enable SysTick IRQ and SysTick Timer
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}




//******************************************************************************************
// SysTick Interrupt Handler
//******************************************************************************************
void SysTick_Handler(void){
	msTicks++;
	heartbeat = true;
	heart_count++;
}

//******************************************************************************************
// Delay in ms
//******************************************************************************************
void delay (uint32_t T){
	msTicks = 0;
  while ((msTicks) < T);
}


//******************************************************************************************
// Fetch the ms tick counter value
//******************************************************************************************
uint32_t get_tick(){
	return msTicks;
}

