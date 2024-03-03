/*
 * Servo_Move.c
 *
 *  Created on: Feb 12, 2024
 *      Author: A
 */
#include "Servo_Move.h"
#include "algorithm.h"
#include "systick.h"



int deltaX = 0;					//Division variable for control of movement
int x_Positioning;
int step_size_x;
int step_size_y;

void Motor_Position(void)
{


	TIM2->CCR1 = xPos;
	TIM2->CCR2 = yPos;
}


void control_X(void)
{


		step_size_x = (xCmd - xPos)/2;
		xPos += step_size_x;




}


void control_Y(void)
{

		step_size_y = (yCmd - yPos)/2;
		yPos += step_size_y;


}

