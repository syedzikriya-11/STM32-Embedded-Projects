
/*
 * header.h
 *
 *  Created on: Sep 2, 2026
 *      Author: user
 */

 #ifndef HEADER_H_
#define HEADER_H_

//GPIO BUS
#define RCC_AHB1ENR (*(volatile uint32_t *)0x40023830)

//pullup resister
#define GPIOC_PUPDR (*(volatile uint32_t *)0x4002080C)

// pb14,pb13(green_led,red_led) GPIOB
#define GPIOB_MODER (*(volatile uint32_t *)0x40020400)
#define GPIOB_ODR (*(volatile uint32_t *)0x40020414)

//sw_8,sw_9(up,down) GPIOC
#define GPIOC_MODER (*(volatile uint32_t *)0x40020800)
#define GPIOC_IDR (*(volatile uint32_t *)0x40020810)

#endif /* HEADER_H_ */

