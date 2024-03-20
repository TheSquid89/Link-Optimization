#include "tim.h"
#include "uart.h"
#include "stm32f4xx.h"
#include <stdio.h>
#include "scanning_function.h"

#define GPIOAEN			(1U<<0)
#define PIN5			(1U<<5)
#define LED				PIN5


void pseudo_delay(void);
void tim2_pa0_pa1_pwm_set_dutycycle(uint8_t ch, uint32_t dutycycle);
void uart2_tx_init(void);
//void scanning_function(void);



int main()
{
	/*init pwm at pa0 and pa1 */
	tim2_pa0_pa1_pwm_init();
	tim2_pa0_pa1_pwm_set_dutycycle(1,100);
	tim2_pa0_pa1_pwm_set_dutycycle(2,100);
	uart2_tx_init();


	printf("welcome");

	while(1)
	{

		printf("check");

	}
}




