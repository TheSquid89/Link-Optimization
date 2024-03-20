#include "uart.h"

#define CR1_TE 				(1U<<3)
#define CR1_UE 				(1U<<13)
#define SR_TXE 				(1U<<7)
#define CR1_RE				(1U<<2)
#define SR_RXNE				(1U<<5)

#define GPIOAEN				(1U<<0)
#define UART2EN				(1U<<17)

#define SYS_FREQ			16000000
#define APB1_CLK			SYS_FREQ

#define UART_BAUDRATE		115200

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate);
static uint16_t compute_uart_BD(uint32_t PeriphClk, uint32_t BaudRate);

void uart2_write(int ch);

char kbhit(void)
{
	while(USART2->SR & SR_RXNE)
	{

	}
	return USART2->DR;
}

char uart2_read(void)
{
	/*make sure the transmit data register is not empty RXNE flag*/
	while(!(USART2->SR & SR_RXNE)){}	//to read a register we use the & operation

	/* read data */
	return USART2->DR;
}

int __io_putchar(int ch) //allows printf to function calling the uart2_write(ch)
{
	uart2_write(ch);
	return ch;
}


void uart2_write(int ch)
{
	/*make sure the transmit data register is empty*/
	while(!(USART2->SR & SR_TXE)){}	//to read a register we use the & operation
	/*write to transmit data register*/

	USART2->DR = (ch & 0xFF);
}

void uart2_rxtx_init(void)
{
	/* ************* configure uart gpio pin ************/
	 //1. enable clock access to gpio a
	RCC->AHB1ENR |= GPIOAEN;
	 // 2. set PA2 mode to alternate function mode
	GPIOA->MODER &= ~(1U<<4);
	GPIOA->MODER |= (1U<<5);
	 // 3. set PA2 alternate function type to UART_TX (AF07)
	GPIOA->AFR[0] |= (1U<<8);
	GPIOA->AFR[0] |= (1U<<9);
	GPIOA->AFR[0] |= (1U<<10);
	GPIOA->AFR[0] &= ~(1U<<11);


	// 2. set PA3 mode to alternate function mode
	GPIOA->MODER &= ~(1U<<6);
	GPIOA->MODER |=  (1U<<7);
	// 3. set PA3 alternate function type to UART_RX (AF07)
	GPIOA->AFR[0] |= (1U<<12);
	GPIOA->AFR[0] |= (1U<<13);
	GPIOA->AFR[0] |= (1U<<14);
	GPIOA->AFR[0] &= ~(1U<<15);
	/************** configure uart gpio pin ************/
	//Enable clock access to uart2
	RCC->APB1ENR |= UART2EN;
	//configure baudrate (there is an equation which is the bus frequency)
	uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);
	//configure the transfer direction
	USART2->CR1 = CR1_TE | CR1_RE;
	//enable uart module
	USART2->CR1 |= CR1_UE;		//the OR operator (|) keeps all 32 bits the same and only changes 13
								//if the = operator is used than it will set all but 13 to zero and change only 13


}




void uart2_tx_init(void)
{
	/* ************* configure uart gpio pin ************/
	 //1. enable clock access to gpio a
	RCC->AHB1ENR |= GPIOAEN;
	 // 2. set PA2 mode to alternate function mode
	GPIOA->MODER &= ~(1U<<4);
	GPIOA->MODER |= (1U<<5);
	 // 3. set PA2 alternate function type to UART_TX (AF07)
	GPIOA->AFR[0] |= (1U<<8);
	GPIOA->AFR[0] |= (1U<<9);
	GPIOA->AFR[0] |= (1U<<10);
	GPIOA->AFR[0] &= ~(1U<<11);

	/************** configure uart gpio pin ************/
	//Enable clock access to uart2
	RCC->APB1ENR |=UART2EN;
	//configure baudrate (there is an equation which is the bus frequency)
	uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);
	//configure the transfer direction
	USART2->CR1 = CR1_TE;
	//enable uart module
	USART2->CR1 |= CR1_UE;		//the OR operator (|) keeps all 32 bits the same and only changes 13
								//if the = operator is used than it will set all but 13 to zero and change only 13


}

void USART_Delay(uint32_t us) {
	uint32_t time = 100*us/7;
	while(--time);
}



static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate)
{
	USARTx->BRR = compute_uart_BD(PeriphClk,BaudRate);
}


static uint16_t compute_uart_BD(uint32_t PeriphClk, uint32_t BaudRate)
{
	return ((PeriphClk + (BaudRate/2U))/BaudRate);
}
