/*
 * usart.c
 *
 *  Created on: 09 сент. 2013 г.
 *      Author: Bird
 */
#include "stm32f10x.h"
#include "usart.h"

void UsartInit(USART_TypeDef *USART) {
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	USART_ClockInitTypeDef USART_ClockInitStructure;

	if (USART == USART1) {
		//Enable bus clocks
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
		//Set USART1 Tx (PA.09) as AF push-pull
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		//Set USART1 Rx (PA.10) as input floating
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		//Write USART1 parameters
		USART_Init(USART1, &USART_InitStructure);
		//Enable USART1
		USART_Cmd(USART1, ENABLE);
	} else if (USART == USART2) {
		//Enable bus clocks
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
		//Set USART2 Tx (PA.02) as AF push-pull
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		//Set USART1 Rx (PA.3) as input floating
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	} else {
		//Enable bus clocks
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
		//Set USART1 Tx (PB.10) as AF push-pull
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		//Set USART1 Rx (PB.11) as input floating
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	}

	//Set USART paramenhs
	USART_ClockStructInit(&USART_ClockInitStructure);
	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_ClockInit(USART1, &USART_ClockInitStructure);
	//Write USART1 parameters
	USART_Init(USART1, &USART_InitStructure);
	//Enable USART1
	USART_Cmd(USART1, ENABLE);
}

/*void UsartPut(USART_TypeDef *USART, uint8_t ch) {
	USART_SendData(USART, (uint8_t) ch);
	//Loop until the end of transmission
	while(USART_GetFlagStatus(USART, USART_FLAG_TC) == RESET);
}*/

uint8_t UsartGet(USART_TypeDef *USART) {
	while ( USART_GetFlagStatus(USART, USART_FLAG_RXNE) == RESET);
	return (uint8_t)USART_ReceiveData(USART);
}

