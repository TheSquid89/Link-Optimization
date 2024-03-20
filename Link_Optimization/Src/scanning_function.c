/*
 * scanning_function.c
 *
 *  Created on: Jan 24, 2024
 *      Author: Adam Robinson
 */

#include "scanning_function.h"
#include "tim.h"
#include "uart.h"
#include "algorithm.h"



void scanning_function(void){

	for(xPos = 91; xPos < 400;)
	{
		xPos = xPos + 20;
		TIM2->CCR1 = xPos;
		pseudo_delay();
		for(yPos = 190; yPos <230; yPos++)
		{
			yPos = yPos + 5;
			TIM2->CCR2 = yPos;
			pseudo_delay();
		}
		pseudo_delay();
	}

}
