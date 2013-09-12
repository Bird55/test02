/*
 * usart.h
 *
 *  Created on: 09 сент. 2013 г.
 *      Author: Bird
 */

#ifndef USART_H_
#define USART_H_

#define USART_1	1
#define USART_2	2
#define USART_3	3

void UsartInit(USART_TypeDef *USART);
void UsartPut(USART_TypeDef *USART, uint8_t ch);
uint8_t UsartGet(USART_TypeDef *USART);

#endif /* USART_H_ */
