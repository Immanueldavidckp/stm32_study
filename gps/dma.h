#ifndef DMA_H_
#define DMA_H_

#include "base.h"

#define DMA1_S5CR       (*(volatile int *)(DMA1_BASE + 0x90))
#define DMA1_S5NDTR     (*(volatile int *)(DMA1_BASE + 0x94))
#define DMA1_S5PAR      (*(volatile int *)(DMA1_BASE + 0x98))
#define DMA1_S5M0AR     (*(volatile int *)(DMA1_BASE + 0x9C))
#define DMA1_HISR       (*(volatile int *)(DMA1_BASE + 0x04))
#define DMA1_HIFCR      (*(volatile int *)(DMA1_BASE + 0x0C))

#define DMA_HISR_TCIF5  (1 << 16)
#define DMA_HIFCR_CTCIF5 (1 << 16)

#define BUFFER_SIZE 64


#endif 

