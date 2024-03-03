/*
 * PID.h
 *
 *  Created on: Feb 18, 2024
 *      Author: A
 */

#include "tim.h"
#include "Servo_Move.h"



#ifndef PID_H_
#define PID_H_
#include "tim.h"
#include "algorithm.h"
#include "Servo_Move.h"
#include "algorithm.h"

extern int output_x;
extern int output_y;
extern float KP;
extern float KI;
extern float KD;
extern float DT;

void Motor_Position(void);
void PID_function(void);
int PID_Controller_Y(int yPos, int yPos_abs);
int PID_Controller_X(int xPos, int xPos_abs);


#endif /* PID_H_ */
