/*
 * process_console.h
 *
 *  Created on: Feb 8, 2024
 *      Author: A
 */
#include "uart.h"
#include "tim.h"
#include "systick.h"
#include "stm32f4xx.h"
#include "Servo_Move.h"
#include "scanning_function.h"
#include <stdio.h>

extern int xCmd;
extern int yCmd;

void uart2_rxtx_init(void);
void tim2_pa0_pa1_pwm_init(void);
void tim2_pa0_pa1_pwm_set_dutycycle(uint8_t ch, uint32_t dutycycle);
void uart2_write(int ch);
int __io_putchar(int ch);
char uart2_read(void);
char kbhit(void);

#ifndef PROCESS_CONSOLE_H_
#define PROCESS_CONSOLE_H_

extern uint8_t mode;


#endif /* PROCESS_CONSOLE_H_ */
