/*
 * Servo_Move.h
 *
 *  Created on: Feb 12, 2024
 *      Author: A
 */

#ifndef SERVO_MOVE_H_
#define SERVO_MOVE_H_
#include "tim.h"
#include "algorithm.h"
#include "PID.h"
#include "process_console.h"
#include "systick.h"
extern float xPos;
extern float yPos;
extern int xPos_abs;
extern int yPos_abs;
extern int deltX;
extern int deltY;
extern float xVar;
extern float xPositioning;


void pseudo_delay(void);
void Motor_Position(void);
void control_Y(void);
void control_X(void);
uint32_t Read_RSSI();
void X_vector(void);

#endif /* SERVO_MOVE_H_ */
