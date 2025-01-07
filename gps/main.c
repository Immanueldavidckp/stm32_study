#include <stdint.h>
#include "uart.h"
#include "dma.h"
#include "gpio.h"




static volatile char rx_buffer[BUFFER_SIZE]; // DMA receive buffer






void GPIOA_Init(void);
void UART2_Init(void);
void DMA_Init(void);

int main(void) {
    GPIOA_Init();
    UART2_Init();
    DMA_Init();

    while (1) {
        // Check if DMA transfer complete
      //  if (DMA1_HISR & DMA_HISR_TCIF5) {
     //       DMA1_HIFCR |= DMA_HIFCR_CTCIF5; // Clear transfer complete flag
            // Process received data in rx_buffer
            for (int i = 0; i < BUFFER_SIZE; i++) {
                while (!(UART2_SR & (1U << 7))); // Wait until TXE
                UART2_DR = rx_buffer[i];        // Echo received data
          //  }
        }
    }
}

void GPIOA_Init(void) {
    RCC_AHB1ENR |= (1U << 0); 

    
    GPIOA_MODER &= ~((3U << 4) | (3U << 6));
    GPIOA_MODER |= ((2U << 4) | (2U << 6));

    
    GPIOA_AFRL &= ~((15U << 8) | (15U << 12));
    GPIOA_AFRL |= ((7U << 8) | (7U << 12));
}

void UART2_Init(void) {
    RCC_APB1ENR |= (1U << 17); // Enable UART2 clock

    UART2_BRR = 16000000 / 9600; // Set baud rate to 9600 (assuming 16 MHz clock)

    UART2_CR3 |= (1U << 6); // Enable DMA for UART reception

    UART2_CR1 |= (1U << 3) | (1U << 2); // Enable UART transmitter and receiver
    UART2_CR1 |= (1U << 13);            // Enable UART
}

void DMA_Init(void) {
    RCC_AHB1ENR |= (1U << 21); 

    DMA1_S5CR &= ~(1U << 0);

    DMA1_S5CR = 0; 

    
    DMA1_S5PAR = (uint32_t)&UART2_DR;       
    DMA1_S5M0AR = (uint32_t)rx_buffer;    
    DMA1_S5NDTR = BUFFER_SIZE;           

    DMA1_S5CR |= (4U << 25);  
    DMA1_S5CR |= (1U << 10); 
    DMA1_S5CR |= (1U << 8);   
    DMA1_S5CR |= (1U << 16);  

    DMA1_S5CR |= (1U << 0); 
}
