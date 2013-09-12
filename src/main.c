/*
 * main.c
 *
 *  Created on: 08 сент. 2013 г.
 *      Author: Bird
 */

#include "stm32f10x.h"
#include <stdio.h>
#include "usart.h"


int main(void) {
	char ch[30];
	int32_t a1,a2;
	UsartInit(USART1);
	printf("\r\n USART1 Test \r\n");
	printf("Enter any text: ");
	scanf("%s",ch);
	printf("\r\nYou entered: ");
	printf("%s\r\n",ch);
	while (1) {
		printf("\r\nEnter first number: ");
		scanf("%ld",&a1);
		printf("%ld", a1);
		printf("\r\nEnter second number: ");
		scanf("%ld",&a2);
		printf("%ld\r\n", a2);
		printf("Sum: %ld + %ld = %ld\r\n",a1, a2, a1 + a2);
	}
}

