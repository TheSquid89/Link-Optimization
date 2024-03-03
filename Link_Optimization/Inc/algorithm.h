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

extern int RSSI_OLD;
extern int RSSI_NEW;

extern int rssi;

#endif /* ALGORITHM_H_ */
