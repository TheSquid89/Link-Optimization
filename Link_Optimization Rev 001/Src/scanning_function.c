/*
 * scanning_function.c
 *
 *  Created on: Jan 24, 2024
 *      Author: Adam Robinson
 */

#include "scanning_function.h"
#include "algorithm.h"


#define MAX_X_POSITIONS 500
#define MAX_Y_POSITIONS 250

int x_positions[MAX_X_POSITIONS];
int rssiX_values[MAX_X_POSITIONS];
int y_positions[MAX_Y_POSITIONS];
int rssiY_values[MAX_Y_POSITIONS];

float frssiX = -150;
int signed maxX_rssi;
int signed maxX_rssi_position;

void perform_scanningX() {



	maxX_rssi = -200;
	maxX_rssi_position = 0;
	xPos = 81;
    for (int i = 81; i < MAX_X_POSITIONS; i+=5)
    {

        xCmd = i;
        control_X();
        Motor_Position();
        delay(10);

//        frssiX = 30.*sin(((i-100)*3.14)/300) - 70;
//        frssiX = Read_RSSI();

        float frssiTemp;
         frssiX = -200;
         for (int j = 0; j< 10; j++)
         {
         	frssiTemp = Uart1_Read();
         	if (frssiTemp > frssiX) frssiX = frssiTemp;
         }

        printf("X position i: %d\r\n", i);


		if (frssiX > maxX_rssi) {
			maxX_rssi = frssiX;
			maxX_rssi_position = i;

		}
		printf("Max RSSI: %i\n\r", maxX_rssi);
        x_positions[i] = i;
        rssiX_values[i] = frssiX;


    }


    xPos = maxX_rssi_position;
    xCmd = xPos;
    printf("**Max xPos: %f**\r\n", maxX_rssi_position);
    Motor_Position();

}

float frssiY = -150;
float maxY_rssi;
float maxY_rssi_positions;


void perform_scanningY() {


	maxY_rssi = -128;
	maxY_rssi_positions = 0;
	yCmd = 150;
    for (int i = 150; i < MAX_Y_POSITIONS; i+=5)
    {

        yCmd = i;
        control_Y();
        Motor_Position();
        delay(10);


//        frssiY = 30.*sin(((i-140)*3.14)/100) - 70;
      float frssiTemp;
        frssiY = -1000;
        for (int j = 0; j< 10; j++)
        {
        	frssiTemp = Uart1_Read();
        	if (frssiTemp > frssiY) frssiY = frssiTemp;
        }

       printf("Y position i: %d\r\n", i);


		if (frssiY > maxY_rssi) {
			maxY_rssi = frssiY;
			maxY_rssi_positions = i;
		}

        y_positions[i] = i;
        rssiY_values[i] = frssiY;


    }


    yPos = maxY_rssi_positions;
    yCmd = yPos;

    printf("**Max Y Pos: %f**\r\n", maxY_rssi_positions);
    Motor_Position();

}



