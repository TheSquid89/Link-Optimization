/*
 * uart1.c
 *
 *  Created on: Feb 9, 2024
 *      Author: A
 */

/********* Set ***********/
/* CLOCK FOR USART1: APB2 100 MHZ
 * GPIOX ENABLE
 * 		CLOCK FOR GPIOA: ABH1
 * UART1EN
 * SYSTEM CLOCK
 * CR1_TE
 * CR1_UE
 * SR_TXE
 * CR1_RE
 * SR_RXNE
 * ALTERNATE FUNCTION 07
 * PIN:
 * 		PA9 USART1_TX
 * 		PA10 USART_RX
 */

#include "uart1.h"

#define UARTEN 			(1U<<4)
#define GPIOAEN			(1U<<0)
#define SYS_FREQ		16000000
#define APB2_CLK		SYS_FREQ

#define CR1_TE			(1U<<3)
#define CR1_RE			(1U<<2)
#define CR1_UE			(1U<<13)

#define SR_TXE			(1U<<7)
#define SR_RXNE			(1U<<5)

#define UART_BAUDRATE	9600

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate);
static uint16_t compute_uart_BD(uint32_t PeriphClk, uint32_t BaudRate);




char Uart1_Read(void)
{
	while(!(USART1->SR & SR_RXNE)){}

	return USART1->DR;
}

void Uart1_Write(int ch)
{
	while(!(USART1->SR & SR_TXE)){}

	USART1->DR = (ch & 0xFF);
}

void Uart1_Init(void)
{
/* ENABLE CLOCK TO GPIOA */
	RCC->AHB1ENR |= GPIOAEN; //CLOCK ACCESS TO GPIOA


/*PA 9 TX */
	GPIOA->MODER &=	~(1U<<18); //SET BIT 18 TO ZERO
	GPIOA->MODER |=  (1U<<19); //SET BIT 19 TO 1
/* SET AFRH TO 07 0111 */
	GPIOA->AFR[1] |=  (1U<<4);
	GPIOA->AFR[1] |=  (1U<<5);
	GPIOA->AFR[1] |=  (1U<<6);
	GPIOA->AFR[1] &= ~(1U<<7);




/*PA 10 RX */
	GPIOA->MODER &= ~(1U<<20);	//SET BIT 20 TO 0
	GPIOA->MODER |=  (1U<<21);	//SET BIT 21 TO 1
/* SET AFRH TO 07 0111 */
	GPIOA->AFR[1] |=  (1U<<8);
	GPIOA->AFR[1] |=  (1U<<9);
	GPIOA->AFR[1] |=  (1U<<10);
	GPIOA->AFR[1] &= ~(1U<<11);

/*ENABLE CLOCK ACCESS TO UART1*/
	RCC->APB2ENR |= UARTEN;

/*BAUDRATE CONFIGURE*/
	uart_set_baudrate(USART1, APB2_CLK, UART_BAUDRATE);

/* configure Transfer direction*/
	USART1->CR1 = CR1_TE | CR1_RE;
/* configure uart module*/
	USART1->CR1 |= CR1_UE;


}
static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate)
{
	USARTx->BRR = compute_uart_BD(PeriphClk,BaudRate);
}


static uint16_t compute_uart_BD(uint32_t PeriphClk, uint32_t BaudRate)
{
	return ((PeriphClk + (BaudRate/2U))/BaudRate);
}
