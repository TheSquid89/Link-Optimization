/*
 * Servo_Move.c
 *
 *  Created on: Feb 12, 2024
 *      Author: A
 */
#include "Servo_Move.h"




float deltX = 8;	//Division variable for control of movement
float deltY = 8;
int x_Positioning;
int step_size_x;
int step_size_y;
uint16_t count;
bool move_done;
//volatile uint32_t msTicks;

void Motor_Position(void)
{



	TIM2->CCR1 = xPos;
	TIM2->CCR2 = yPos;

//	printf("xpos: %f\n\r", xPos);
//	printf("ypos: %f\n\r", yPos);



}


void control_X(void)
{
	step_size_x = (xCmd - xPos)/deltX;
	xPos += step_size_x;

}


void control_Y(void)
{
	step_size_y = (yCmd - yPos)/deltY;
	yPos += step_size_y;
}

void motor_control(void)
{
	step_size_x = (xCmd - xPos)/deltX + 1;
	xPos += step_size_x;

	step_size_y = (yCmd - yPos)/deltY + 1;
	yPos += step_size_y;

	if(step_size_x == 0 && step_size_y == 0 )
	{
		move_done = true;
	}
	else
	{
		move_done = false;
	}
	printf("xC:%i xP:%i Dx: %f yC:%i yP:%i Dy:%f MoveDone:%i\n\r", xCmd, xPos, deltX, yCmd, yPos, deltY, move_done);
}

