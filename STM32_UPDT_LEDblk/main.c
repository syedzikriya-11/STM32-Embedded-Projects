#include "STM32f4xx.h"





#define GPIOENR (1U<<1)
#define LED_PIN (1U<<13)



int main(){
	RCC->AHB1ENR |=GPIOENR;
	GPIOB->MODER &= ~(3U<<26);
	GPIOB->MODER |= (1U<<26);

	while(1){

		GPIOB->ODR ^=LED_PIN;
		for(volatile int i=0;i<1000000;i++){}


	}
}
