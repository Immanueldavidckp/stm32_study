#ifndef DMA_H_
#define DMA_H_

#include "base.h"

#define Strem5   (0x018 * 5)

#define DMA1_S5CR       (*(volatile int *)(DMA1_BASE + 0x010 + Strem5))
#define DMA1_S5NDTR     (*(volatile int *)(DMA1_BASE + 0x014 + Strem5))
#define DMA1_S5PAR      (*(volatile int *)(DMA1_BASE + 0x018 + Strem5))
#define DMA1_S5M0AR     (*(volatile int *)(DMA1_BASE + 0x01C + Strem5))
#define DMA1_S5M1AR     (*(volatile int *)(DMA1_BASE + 0x020 + Strem5))
#define DMA1_HISR       (*(volatile int *)(DMA1_BASE + 0x04))
#define DMA1_HIFCR      (*(volatile int *)(DMA1_BASE + 0x0C))

#define DMA_HISR_TCIF5  (1 << 16)
#define DMA_HIFCR_CTCIF5 (1 << 16)

#define BUFFER_SIZE 64


#endif 


