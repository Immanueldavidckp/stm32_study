#include <stdint.h>
#include "uart.h"
#include "dma.h"
#include "gpio.h"

#define UART2_SR_TXE  (1<<7)
#define UART2_SR_RXE  (1<<5)




static volatile char tx_buffer;
//static volatile char rx_buffer[10];



void UART_SendChar(char c);
char UART_ReceiveChar(void);
void UART_SendString(char *string);

void GPIOA_Init(void);
void UART2_Init(void);
void DMA_Init(void);

int main(void) {
	//char v;
    GPIOA_Init();
    UART2_Init();
    DMA_Init();

	    UART_SendString("STM32 UART Test\r\n");

    while (1) {
			  
     char receivedChar = UART_ReceiveChar();
			 UART_ReceiveChar();
			  UART_SendChar(receivedChar);
	/*		 for(int i=0;i>10;i++)
			{
        UART_SendChar(tx_buffer[i]);
			} */
					
    }
	
}

void GPIOA_Init(void) {
    RCC_AHB1ENR |= (1U << 0); 

    
    GPIOA_MODER &= ~((3U << 4) | (3U << 6));
    GPIOA_MODER |= ((2U << 4) | (2U << 6));

    
    GPIOA_AFRL &= ~((15U << 8) | (15U << 12));
    GPIOA_AFRL |= ((7U << 8) | (7U << 12));
	
	
		GPIOA_MODER |= (1U<<10);
		GPIOA_MODER &=~(1U<<11);
	
}

void UART2_Init(void) {
    RCC_APB1ENR |= (1U << 17); // Enable UART2 clock

    UART2_BRR = 16000000 / 9600; // Set baud rate to 9600 (assuming 16 MHz clock)

    UART2_CR3 |= (1U << 6); // Enable DMA for UART reception
    
    UART2_CR1 |= (1U << 5) | (1U << 7);	

    UART2_CR1 |= (1U << 3) | (1U << 2); // Enable UART transmitter and receiver
    UART2_CR1 |= (1U << 13);            // Enable UART
}

void DMA_Init(void) {
    RCC_AHB1ENR |= (1U << 21); 

    DMA1_S5CR &= ~(1U << 0);

    DMA1_S5CR = 0; 

    
    DMA1_S5M1AR = (uint32_t)&UART2_DR;       
    DMA1_S5M0AR =(uint32_t)&tx_buffer;    
    DMA1_S5NDTR = 1;           
  //  DMA1_S5NDTR = 10;
    DMA1_S5CR |= (4U << 25);  
    DMA1_S5CR &=~(1U << 10); 
    DMA1_S5CR |= (1U << 8);   
    DMA1_S5CR |= (2U << 16);  
	  DMA1_S5CR &=~(1U << 7);
	  DMA1_S5CR &=~(1U << 6);

    DMA1_S5CR |= (1U << 0);  
}
void UART_SendString(char *string) {
    while (*string) {
        UART_SendChar(*string++);
    }
}
char UART_ReceiveChar(void) {
    while (!(UART2_SR & UART2_SR_RXE)); // Wait until RX buffer is not empty
    return (char)UART2_DR;
}
void UART_SendChar(char c) {
    while (!(UART2_SR & UART2_SR_TXE)); // Wait until TX buffer is empty
    UART2_DR = c;
}


