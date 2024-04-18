/*
 * algorithm.c
 *
 *  Created on: Feb 12, 2024
 *      Author: A
 */

#include "algorithm.h"
#include "Servo_Move.h"
#include "stm32f4xx.h"
#include <stdint.h>
#include "uart1.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_READINGS 3
#define NUM_Y_POSITIONS 2
#define NUM_X_POSITIONS 2



signed char d;


extern int signed vectorY;
extern int signed vectorX;


int random_index(int signed min,int signed max) {
    return min + rand() % (max - min + 1);
}
float frssiTemp = -1000;

signed char Read_RSSI() // Change return type to uint32_t
{

//	}
	frssiY = -1000;

    for (int j = 0; j< 15; j++)
    {
    	d = Uart1_Read();
    	frssiTemp = d;
    	if (frssiTemp > frssiY)
    	{
    		frssiY = frssiTemp;
//    	    printf("frssiY %f\n\r", frssiY);
    	}

    }
//    printf("frssiY %f\n\r", frssiY);
//    printf("frssiTemp %f\n\r", frssiTemp);
return frssiY;
}


signed char sum=0;
float averageRSSI_X()
{
//    sum = 0;
    for (int i = 0; i < NUM_READINGS; i++) {
        sum += Uart1_Read();
        printf("sum: %i\n\r", sum);
        delay(10);
    }

  return sum / NUM_READINGS;
}
float averageRSSI_Y()
{
	sum = 0;
	for (int i = 0; i< NUM_READINGS; i++)
	{
		sum += Read_RSSI();
//		printf("sum Y: %i\n\r", sum);
		delay(10);
	}

	return sum / NUM_READINGS;;
}

// Function to calculate change in RSSI after y movement multiplied by delta y
/*int signed calculateDeltaY(int signed initialRSSI_Y, int signed finalRSSI_Y, int deltaY) {
    vectorY =  (finalRSSI_Y - initialRSSI_Y) * deltaY;
    return vectorY;
}

// Function to calculate change in RSSI after x movement multiplied by delta x
int signed calculateDeltaX(int signed initialRSSI_X, int signed finalRSSI_X, int deltaX) {
    vectorX =  (finalRSSI_X - initialRSSI_X) * deltaX;
    return vectorX;
}

*/

//int avgRSSI_Y;,
//int avgRSSI_X;
int initialRSSI_Y;
//int deltaY;
int finalRSSI_Y;
//int deltaRSSI_Y;
//int deltaX;
int initialRSSI_X;
int finalRSSI_X;
//int deltaRSSI_X;

void initializeGlobalVariables() {
//    avgRSSI_Y = averageRSSI_Y();
//    avgRSSI_X = averageRSSI_X();
    initialRSSI_Y = Read_RSSI();
//    deltaY = 20; // Assuming delta y is 5
    finalRSSI_Y = Read_RSSI();
//    deltaRSSI_Y = calculateDeltaY(initialRSSI_Y, finalRSSI_Y, deltaY);

//    deltaX = 20; // Assuming delta x is 10
    initialRSSI_X = Read_RSSI();
    finalRSSI_X = Read_RSSI(); // Calculate final RSSI after x movement
//    deltaRSSI_X = calculateDeltaX(initialRSSI_X, finalRSSI_X, deltaX);
}


