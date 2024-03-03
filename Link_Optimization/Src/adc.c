/*
 * adc.c
 *
 *  Created on: Jan 12, 2024
 *      Author: Adam Robinson
 */
#include "stm32f4xx.h"
#include "ADC.h"
#define ADC1EN			(1U<<8)
#define GPIOAEN			(1U<<0)
#define ADC_CH1			(1U<<0)
#define ADC_SEQ_LEN_1	0x00
#define CR2_ADON		(1U<<0)
#define CR2_SWSTART		(1U<<30)
#define SR_EOC			(1U<<1)
#define CR2_CONT		(1U<<1)




/*adc configured with 3 channels
 * ch2, ch3, ch5
 * first channel = CH5
 * second = ch2
 * third = ch3
 */


void pa1_adc_init(void)
{
	/*Enable Clock Access to GPIOA*/
	RCC->AHB1ENR |= GPIOAEN;

	/*set the mode of PA1 to analog mode*/
	GPIOA->MODER |= (1U<<2);
	GPIOA->MODER |= (1U<<3);
	/*configure the ADC module*/


	/*enable clock access to ADC*/
	RCC->APB2ENR |= ADC1EN;
	/*configure ADC parameters*/

	//Conversion sequence start
	ADC1->SQR3 = ADC_CH1;
	//conversion sequence length
	ADC1->SQR1 = ADC_SEQ_LEN_1;
	//enable the ADC module
	ADC1->CR2 |= CR2_ADON;


}

void start_conversion(void)
{
	//enable continuous converison
	ADC1->CR2 |= CR2_CONT;
	//start ADC conversion
	ADC1->CR2 |= CR2_SWSTART;

}

uint32_t adc_read(void)
{
	//wait for conversion to be complete
	while(!(ADC1->SR & SR_EOC)){}		//while the & operation is false it will get stuck in this loop
	//read converted result
	return(ADC1->DR);
}
