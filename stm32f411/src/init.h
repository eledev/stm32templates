#ifndef __INIT_H
#define __INIT_H

#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"

#define PLLM_VALUE            12
#define PLLN_VALUE            96
#define PLLP_VALUE            2
#define PLLQ_VALUE            4


void init(void);


#endif
