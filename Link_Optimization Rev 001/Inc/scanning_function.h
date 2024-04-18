/*
 * scanning_function.h
 *
 *  Created on: Jan 24, 2024
 *      Author: A
 */

#ifndef SCANNING_FUNCTION_H_
#define SCANNING_FUNCTION_H_

#include "scanning_function.h"
#include "tim.h"
#include "uart.h"
#include <stdint.h>
#include "stm32f4xx.h"
#include "Servo_Move.h"
#include "algorithm.h"
#include <stdio.h>

//void scanning_function(void);
void perform_scanning();
void fake_rssi();
extern int xPos;
extern int yPos;
extern float frssiY;
extern float maxY_rssi;
extern float maxY_rssi_position;

#endif /* SCANNING_FUNCTION_H_ */
