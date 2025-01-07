#ifndef UART_H_
#define UART_H_

#include "base.h"

#define UART2_CR1       (*(volatile int *)(UART2_BASE + 0x0C))
#define UART2_BRR       (*(volatile int *)(UART2_BASE + 0x08))
#define UART2_DR        (*(volatile int *)(UART2_BASE + 0x04))
#define UART2_SR        (*(volatile int *)(UART2_BASE + 0x00))
#define UART2_CR3       (*(volatile int *)(UART2_BASE + 0x14))

#endif

