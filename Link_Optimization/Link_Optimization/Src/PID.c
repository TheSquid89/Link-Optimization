/*
 * PID.c
 *
 *  Created on: Feb 18, 2024
 *      Author: A
 */
#include "PID.h"
#include "stm32f4xx.h"


// PID Controller Parameters
float KP = 25.0;   // Proportional gain
float KI = .01;   // Integral gain changed from .1
float KD = .01;  // Derivative gain changed from .01
float DT = .01;  // Time step (sampling time)

// PID Controller Variables
float error_x = 0.;
float prev_error_x = 0.;
float integral_x = 0.;
float derivative_x = 0.;
float output_x = 0.;

float error_y = 0.;
float prev_error_y = 0.;
float integral_y = 0.;
float derivative_y = 0.;
float output_y = 0.;

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

    xCmd += output_x;
    }
}

int PID_Controller_Y(int yCmd, int yPos)
{
	  error_y = yCmd - yPos;

	  if(error_y != 0)
	  {

	  integral_y += error_y * DT;

	  derivative_y = (error_y - prev_error_y) / DT;

	  output_y = KP * error_y + KI * integral_y + KD * derivative_y;

	  prev_error_y = error_y;

	  yCmd += output_y;
	  }
}
