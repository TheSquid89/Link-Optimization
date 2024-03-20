/*
 * scanning_function.c
 *
 *  Created on: Jan 24, 2024
 *      Author: Adam Robinson
 */

#include "scanning_function.h"
#include "tim.h"
#include "uart.h"


void scanning_function(void)
{
	for(int x = -25;x<400;)
	{
		TIM2->CCR2 = x;
	//	printf("X Value: %i\n\r", x);
			for(int y = 120; y<400;y++)
			{
				TIM2->CCR1 = y;
				pseudo_delay();
		//		printf("Y Value: %i", y);
				if(y==390)
				{

					break;
					pseudo_delay();
				}
			}
		x=x+2;
			if(x==25)
			{
				break;
				pseudo_delay();
			}
	}
	for(int x=400;x>-25;)
	{
		TIM2->CCR2 = x;
			for(int y = 80; y<400;y++)
			{
				TIM2->CCR1 = y;
				pseudo_delay();
					if(y==180)
					{
						break;
						pseudo_delay();
					}
				pseudo_delay();
			}

		x = x-10;

	}
}
