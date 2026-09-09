#include "STM32f4xx.h"

//define GPIO B&C with AHB1ENR
#define GPIOBENR (1U<<1)
#define GPIOCENR (1U<<2)

//configure pin numbers
#define LED_PIN (1U<<14)
#define BUTTON (1U<<8)

int main(){
	//enable clk for GPIO B&C
	RCC->AHB1ENR |=GPIOBENR;
	RCC->AHB1ENR |=GPIOCENR;

	//pull up reg
	GPIOC->PUPDR &= ~(3U << 16);
	GPIOC->PUPDR |=  (1U << 16);

	//GPIOB(LED) as OUTPUT
	GPIOB->MODER &= ~(3U<<28);
	GPIOB->MODER |= (1U<<28);

	//GPIOC(BUTTON) as INPUT
	GPIOC->MODER &= ~(3U<<16);

	while(1){
		if(!(GPIOC->IDR & BUTTON)){
			//LED ON
		GPIOB->BSRR=LED_PIN;
		}

		else{
			//LED OFF
		GPIOB->BSRR=(1U<<30);
		}
	}
}
