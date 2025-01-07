#ifndef GPIO_H_
#define GPIO_H_

#include "base.h"

#define GPIOA_MODER     (*(volatile int *)(GPIOA_BASE + 0x00))
#define GPIOA_ODR       (*(volatile int *)(GPIOA_BASE + 0x14))
#define GPIOA_AFRL      (*(volatile int *)(GPIOA_BASE + 0x20))
#define RCC_AHB1ENR     (*(volatile int *)(RCC_BASE + 0x30))
#define RCC_APB1ENR     (*(volatile int *)(RCC_BASE + 0x40))

#endif


