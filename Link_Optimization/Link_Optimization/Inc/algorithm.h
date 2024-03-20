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

uint32_t Read_RSSI();
int random_index(int min, int max);
uint32_t Average_Rssi(void);
extern int rssi_old;
extern int rssi_new;



#endif /* ALGORITHM_H_ */
