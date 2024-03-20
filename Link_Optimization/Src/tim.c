/*
 * tim.c
 *
 *  Created on: Jan 24, 2024
 *      Author: A
 */
#include "tim.h"


#define	GPIOAEN			(1U<<0)
#define TIM2EN			(1U<<0)
#define CR1_CEN			(1U<<0)


void tim2_pa0_pa1_pwm_init(void)
{
	/*******GPIO Configuration*********/
	/*Enable clock access to GPIOA*/
	RCC->AHB1ENR |= GPIOAEN;
	/*set PA0 and PA1 modes to alternate function mode*/
	/*PA0*/
	GPIOA->MODER &= ~(1U<<0);
	GPIOA->MODER |= (1U<<1);

	/*PA1*/
	GPIOA->MODER &= ~(1U<<2);
	GPIOA->MODER |= (1U<<3);

	/*set alternate function type to TIM2 (AF01 0001)*/
	/*Set AFR for PA0*/
	GPIOA->AFR[0] |= (1U<<0);
	GPIOA->AFR[0] &= ~(1U<<1);
	GPIOA->AFR[0] &= ~(1U<<2);
	GPIOA->AFR[0] &= ~(1U<<3);

	/*Set AFR for PA1*/
	GPIOA->AFR[0] |= (1U<<4);
	GPIOA->AFR[0] &= ~(1U<<5);
	GPIOA->AFR[0] &= ~(1U<<6);
	GPIOA->AFR[0] &= ~(1U<<7);
	/*******Tim2 Configuration*********/
	/*Enable clock access to TIM2*/
	RCC->APB1ENR |= TIM2EN;
	/*set timer prescaler*/
	TIM2->PSC = 80;  // 16 000 000 no divider = 16 000 000
	/*set auto reload value*/
	TIM2->ARR = 400 - 1; //16 000 000 / 100 = 160 000
	/*reset the timer count*/
	TIM2->CNT = 0;
	/*Set PA1 (channel 2) and PA0 (channel 1) to 110 : PWM mode 1 finding OC1M (CH1) and OC2M (CH2) in the reference manual under CCMR1*/
	/*PA0*/
	TIM2->CCMR1 &= ~(1U<<4);
	TIM2->CCMR1 |=  (1U<<5);
	TIM2->CCMR1 |=  (1U<<6);
	/*PA1*/
	TIM2->CCMR1 &= ~(1U<<12);
	TIM2->CCMR1 |=  (1U<<13);
	TIM2->CCMR1 |=  (1U<<14);
	/*Enable ch1 and ch2 search CCER in the reference manual*/
	/*Channel 1*/
	TIM2->CCER |= (1U<<0);
	/*Channel 2*/
	TIM2->CCER |= (1U<<4);
	/*enable timer find timx_cr1 in the reference manual and enable CEN (counter enable)*/
	TIM2->CR1 |= CR1_CEN;

}



void tim2_pa0_pa1_pwm_set_dutycycle(uint8_t ch, uint32_t dutycycle)
{
	/*Select Channel*/
	switch(ch)
	{

	   /*Set duty cycle*/

		case 1:
			TIM2->CCR1 = dutycycle;
			break;
		case 2:
			TIM2->CCR2 = dutycycle;
		default:
			break;
	}

}

void pseudo_delay(void)
{
	for(int i=0;i<50000;i++){}
}
