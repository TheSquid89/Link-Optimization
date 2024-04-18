#include "tim.h"
#include "uart.h"
#include "uart1.h"
#include "systick.h"
#include "PID.h"
#include "algorithm.h"
#include "stm32f4xx.h"
#include "Servo_Move.h"
#include <stdio.h>
#include "scanning_function.h"
#include "process_console.h"
#include <math.h>
#include <stdint.h>
#include <stdbool.h>


#define GPIOAEN			(1U<<0)
#define PIN5			(1U<<5)
#define LED				PIN5



void uart2_rxtx_init(void);
char kbhit(void);
int random_index(int min, int max);
void X_vector(void);
void initializeGlobalVariables();

float deltaX = 1;
float deltaY = 1;
int signed vectorY;
int signed vectorX;

int signed calculateDeltaY(int signed initialRSSI_Y, int signed finalRSSI_Y, float deltaY) {
    vectorY =  (initialRSSI_Y - finalRSSI_Y) * deltaY;
    return vectorY;
}

// Function to calculate change in RSSI after x movement multiplied by delta x
int signed calculateDeltaX(int signed initialRSSI_X, int signed finalRSSI_X, float deltaX) {
    vectorX =  (initialRSSI_X - finalRSSI_X) * deltaX;
    return vectorX;
}

int xPos = 80; // changed from 80
int yPos = 200; // changed from 190
volatile bool heartbeat;
uint8_t mode;

int start_xCmd = 0;
int start_yCmd = 0;

extern uint16_t count;

int main(void)
{
	SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));
	count = 0;
//	TIM2->CCR1 = 0;
//	TIM2->CCR2 = 0;
	tim2_pa0_pa1_pwm_init();
	tim2_pa0_pa1_pwm_set_dutycycle(1,50);
	tim2_pa0_pa1_pwm_set_dutycycle(2,50);
	uart2_rxtx_init();
	SysTick_Init();
	kbhit();
	Uart1_Init();
	SysTick_Handler();
//	perform_scanningX();
//	perform_scanningY();
	RCC->AHB1ENR |= GPIOAEN;
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1U<<11);


	printf("Welcome to Link Optimization\n\r");
	while(1)
	{



		if(heartbeat == true)	//Utilization of hardware clock SysTick by interrupt
		{
			heartbeat = false;	//Sets conditional statement false which is set true in the interrupt handler
			count++;	//increments the counter
			if((count % 50) == 0)	//Conditional statement that flashes LED2 every 50 ms
			{
			GPIOA->ODR ^= LED;
			}
			if(move_done == true)
			{
				Read_RSSI(); 	//Reads RSSI_NEW value
				while(s == 1)
				{

				}
				if(mode == p)
				{

//					PID_Controller_X(vectorX);
//					PID_Controller_Y(vectorY);

					if((count % 10) == 0)
					{
		//					mode = v;
						Read_RSSI();
						initialRSSI_X = frssiY;

						start_xCmd = xCmd;
						xCmd = xCmd + deltaX;
						motor_control();
						Motor_Position();

						delay(10);

						Read_RSSI();
						finalRSSI_X = frssiY;
						printf("final: %i\n\r", finalRSSI_X);
		//					averageRSSI_X();

						calculateDeltaX(initialRSSI_X, finalRSSI_X, deltaX);

						xCmd = start_xCmd + vectorX;

						PID_Controller_X(vectorX);
						motor_control();
						Motor_Position();

						printf("inital: %i vectorX:%i start_xCmd:%i xCmd%i\n\r", initialRSSI_X, vectorX, start_xCmd, xCmd);
/*****************************yCmd********************************/


						Read_RSSI();
						initialRSSI_Y = frssiY;
						start_yCmd = yCmd;


						yCmd = yCmd + deltaY;
						motor_control();
						Motor_Position();

						delay(10);

						Read_RSSI();
						finalRSSI_Y = frssiY;

						calculateDeltaY(initialRSSI_Y, finalRSSI_Y, deltaY);



						yCmd = start_yCmd + vectorY;

						PID_Controller_Y(vectorY);
						motor_control();
						Motor_Position();

						printf("inital: %i vectorY:%i start_yCmd:%i yCmd%i\n\r", initialRSSI_Y, vectorY, start_yCmd, yCmd);


					}
					else
					{
						mode = p;
					}
				}

			}



//			control_X(); 	// First process of PID algorithm in X axis
//			control_Y();
			motor_control();

			Motor_Position(); 	//Debug process which gets stuck in this loop and stops all function
			//printf("count: %i\n\r", count);
		}

	process_console();	//Parsing which reads a keyboard input for manually setting different functions

	}


}







