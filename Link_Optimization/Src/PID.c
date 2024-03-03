/*
 * PID.c
 *
 *  Created on: Feb 18, 2024
 *      Author: A
 */
#include "PID.h"
#include "stm32f4xx.h"


// PID Controller Parameters
float KP = 1.0;   // Proportional gain
float KI = .01;   // Integral gain changed from .1
float KD = .001;  // Derivative gain changed from .01
float DT = 1;  // Time step (sampling time)

// PID Controller Variables
int error_x = 0.;
int prev_error_x = 0.;
int integral_x = 0.;
int derivative_x = 0.;
int output_x = 0.;

int error_y = 0.;
int prev_error_y = 0.;
int integral_y = 0.;
int derivative_y = 0.;
int output_y = 0.;

// Target Position (desired setpoint)
/*********xPos_abs***********/

// Current Position (measured process variable)
/*********xPos***************/


int PID_Controller_X(int xCmd, int xPos) {
    // Calculate error
    error_x = xCmd - xPos;
    // Calculate integral
    if(error_x != 0)
    {
    integral_x += error_x * DT;
    // Calculate derivative
    derivative_x = (error_x - prev_error_x) / DT;

    // Calculate PID output
    output_x = KP * error_x + KI * integral_x + KD * derivative_x;


    // Update previous error
    prev_error_x = error_x;

    TIM2->CCR1 = output_x;
    }
}

int PID_Controller_Y(int yCmd, int yPos)
{
	  error_y = yCmd - yPos;

	  integral_y += error_y * DT;

	  derivative_y = (error_y - prev_error_y) / DT;

	  output_y = KP * error_y + KI * integral_y + KD * derivative_y;

	  prev_error_y = error_y;

	  return output_y;
}
