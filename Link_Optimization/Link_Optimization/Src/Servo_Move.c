/*
 * Servo_Move.c
 *
 *  Created on: Feb 12, 2024
 *      Author: A
 */
#include "Servo_Move.h"




int deltX = 2;	//Division variable for control of movement
int deltY = 2;
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
		step_size_x = (xCmd - xPos)/deltX;
		xPos += step_size_x;
}


void control_Y(void)
{
		step_size_y = (yCmd - yPos)/deltY;
		yPos += step_size_y;
}

int rssi_old;
int rssi_new;
int xPos_old;
int xPos_new;
float nom_rssi;
float vect;
float xVar;

void X_vector(void)
{

	rssi_old;

	xPos_old = xCmd;

	xCmd + 4;

	xPos_new = xCmd;

	xVar = xPos_new - xPos_old;

//	rssi_new = Avg_Rssi();

	nom_rssi = rssi_old - rssi_new;

	vect = xVar * nom_rssi;

	xCmd = vect;

}
