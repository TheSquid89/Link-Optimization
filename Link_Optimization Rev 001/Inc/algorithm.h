/*
 * algorithm.h
 *
 *  Created on: Feb 12, 2024
 *      Author: A
 */

#ifndef ALGORITHM_H_
#define ALGORITHM_H_
#include "stm32f4xx.h"
#include <stdint.h>
#define ARRAY_SIZE 7
//int signed calculateDeltaX(int signed initialRSSI_X, int signed finalRSSI_X, int deltaX);
//int signed calculateDeltaY(int signed initialRSSI_Y, int signed finalRSSI_Y, int deltaY);
signed char Read_RSSI();
int random_index(int min, int max);
uint32_t Average_Rssi(void);
//void initializeGlobalVariables();
extern int initialRSSI_Y;
extern float aveRSSI_Y;
extern float aveRSSI_X;
//extern int deltaY;
//extern int deltaX;
extern int initialRSSI_X;
extern int finalRSSI_Y;
//extern int deltaRSSI_Y;
extern int finalRSSI_X;
//extern int deltaRSSI_X;

extern signed char d;


#endif /* ALGORITHM_H_ */
