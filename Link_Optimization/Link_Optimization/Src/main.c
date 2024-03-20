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

float xPos = 80;
float yPos = 190;
int RSSI_OLD;
int RSSI_NEW;
//signed char d;
volatile bool heartbeat;
uint8_t mode;
enum {m,v,p};

int main(void)
{
	SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));
	uint16_t count = 0;
	tim2_pa0_pa1_pwm_init();
	tim2_pa0_pa1_pwm_set_dutycycle(1,50);
	tim2_pa0_pa1_pwm_set_dutycycle(2,50);
	uart2_rxtx_init();
	SysTick_Init();
	kbhit();
	Uart1_Init();
	SysTick_Handler();
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
			Read_RSSI(); 	//Reads RSSI_NEW value
			if(mode != m)
			{

				PID_Controller_X(xCmd, xPos);
				PID_Controller_Y(yCmd, yPos);

				if((count % 10) == 0)
				{
					mode = v;
				}
				else
				{
					mode = p;
				}
			}


			control_X(); 	// First process of PID algorithm in X axis
			control_Y();

			Motor_Position(); 	//Debug process which gets stuck in this loop and stops all function
		}

	process_console();	//Parsing which reads a keyboard input for manually setting different functions

	}

}








