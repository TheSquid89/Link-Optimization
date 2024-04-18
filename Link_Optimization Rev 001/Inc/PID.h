/*
 * PID.h
 *
 *  Created on: Feb 18, 2024
 *      Author: A
 */




#ifndef PID_H_
#define PID_H_
#include "tim.h"
#include "Servo_Move.h"
#include "algorithm.h"

extern float output_x;
extern float output_y;
extern float KP;
extern float KI;
extern float KD;
extern float DT;
extern int signed vectorX;
extern int signed vectorY;

void Motor_Position(void);
void PID_function(void);
int PID_Controller_Y(int signed vectorY);
int PID_Controller_X(int signed vectorX);


#endif /* PID_H_ */
