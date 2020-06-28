#include "main.h"

int main(void) {
    init();

    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  
    /* Configure MCO1 pin(PA8) in alternate function */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;  
    GPIO_Init(GPIOA, &GPIO_InitStructure);
        
    /* HSE clock selected to output on MCO1 pin(PA8)*/
    //RCC_MCO1Config(RCC_MCO1Source_HSE, RCC_MCO1Div_1);
    RCC_MCO1Config(RCC_MCO1Source_PLLCLK, RCC_MCO1Div_1);

    while(1){
    }
}

#ifdef  USE_FULL_ASSERT
/* 	assert_param(bool) */
void assert_failed(uint8_t* file, uint32_t line){

}

#endif
