#include<stdint.h>
#include "STM32f4xx.h"

#define GPIOAENR  (1U<<0)
#define UART2ENR  (1U<<17)

//defauly system clk is 16Mhz
#define SYS_FRQ   16000000

//perephrial clk for apb1 has same freq as sys_....
#define APB1_CLK   SYS_FRQ

#define UART_BUADRATE 115200

//tx for uart set bit 3 to 1 to enable
#define USART_TE  (1U<<3)


//enable uart UE set 13bit to 1
#define CR1_UE (1U<<13)

//setting status register to uart
#define SR_TXE (1U<<7)

static void uart_set_buadrate(USART_TypeDef *USARTx,uint32_t periphCLK,uint32_t Buadrate);
static uint16_t compute_uart_bd(uint32_t periphCLK,uint32_t Buadrate);
void uart2_write(int ch);
void uart2_tx_init();



int main(void){

	//now initialize UART
	uart2_tx_init();
	while(1){
		//display this char if recived
		uart2_write('R');


	}

}

void uart2_tx_init(){

	/****configure uart gpio pins*****/

	//enable clk
	RCC->AHB1ENR |= GPIOAENR;

	//set moder to alternate mode (01)
	GPIOA->MODER  &=~(3U<<4);
	GPIOA->MODER  |=(2U<<4);


    //AFRL [0](from 0 to 7),  AFRH [1] (from 8 to 13)
	GPIOA->AFR[0] |=(7U<<8);//PA 2 as ALternate



/*******configure UART module*******/

	//enable clk for uart2
	RCC->APB1ENR |=UART2ENR;

	//configure buadrate for uart
	uart_set_buadrate(USART2,APB1_CLK,UART_BUADRATE);

	//transfer direction(tx)
	USART2->CR1 =USART_TE; //"without" putting any "operater" it clears first then set the bit

	//enable uart module
	USART2->CR1 |=CR1_UE;

}

void uart2_write(int ch){


	//while SR is not set i.e, FALSE
	while(!(USART2->SR & SR_TXE));

	//uart data register(8but) setting it
	USART2->DR = (ch & 0xFF);

}

/***after calculating buadrate then set with uart****/
static void uart_set_buadrate(USART_TypeDef *USARTx,uint32_t periphCLK,uint32_t Buadrate){

	//access USART to BRR(buad rate reg)
	USARTx->BRR = compute_uart_bd(periphCLK,Buadrate);
}

/***to configure buadrate we need to calculate it first****/
static uint16_t compute_uart_bd(uint32_t periphCLK,uint32_t Buadrate){
	return ((periphCLK+(Buadrate/2U))/Buadrate);
}
